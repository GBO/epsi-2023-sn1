//
// Created by Killian on 21/03/2023.
//
#include "GameGrid.h"
#include "Application.h"
#include "Tiles.h"
#include "CollisionUtils.h"
#include <fstream>
#include "Player.h"

std::unique_ptr<GameGrid::Tile> GameGrid::Tile::ParseRawTile(RawGameTile* rawTile, sf::Vector2f position)
{
    // Check against all available types, and return nullptr if none match
    switch(rawTile->type)
    {
    case TileType::Ground:
        return std::make_unique<GroundTile>(rawTile, position);
    case TileType::PassagePoint:
        return std::make_unique<PassagePointTile>(rawTile, position);
    case TileType::Path:
        return std::make_unique<PathTile>(rawTile, position);
    case TileType::Soil:
        return std::make_unique<SoilTile>(rawTile, position);
    default:
        return nullptr;
    }
}

void GameGrid::Init()
{
    // Open the file and read the header
    std::ifstream file(m_path, std::ios::binary);
    if(!file.is_open())
    {
        throw std::runtime_error("Failed to open file " + m_path);
    }

    auto* grid = new RawGameGrid;
    file.read(reinterpret_cast<char*>(grid), sizeof(RawGameGrid));

    // Calculate the size of the data
    uint32_t dataSize = grid->tilesetPathSize + grid->tilesSize + grid->entitiesSize;
    {
        auto* newGrid = (RawGameGrid*)malloc(sizeof(RawGameGrid) + dataSize);
        std::memcpy(newGrid, grid, sizeof(RawGameGrid));
        delete grid;
        grid = newGrid;
    }
    // Read the remaining data
    file.read(reinterpret_cast<char*>(grid->data), dataSize);

    // Reserve enough space to store all tiles
    m_tiles.reserve(grid->width * grid->height);

    // Get the tileset path (it is the first field in data)
    std::string tilesetPath(reinterpret_cast<char*>(grid->data), grid->tilesetPathSize);

    // Parse tiles
    auto* rawTile = (RawGameTile*)(grid->data + grid->tilesetPathSize);
    float x = -static_cast<float>(grid->width) / 2.0f;
    float y = -static_cast<float>(grid->height) / 2.0f;
    while(rawTile < (RawGameTile*)(grid->data + grid->tilesetPathSize + grid->tilesSize))
    {
        if(rawTile->size != 14)
        SPDLOG_INFO("size: {}", rawTile->size);
        m_tiles.push_back(Tile::ParseRawTile(rawTile, {x, y}));

        if(rawTile->collidable)
            m_collidableTiles.push_back(&m_tiles.back());

        x += 1.0f;
        if(x >= static_cast<float>(grid->width) / 2.0f)
        {
            x = -static_cast<float>(grid->width) / 2.0f;
            y += 1.0f;
        }

        rawTile = (RawGameTile*)((uint8_t*)rawTile + rawTile->size);
    }

    // TODO: parse entities

    m_width = grid->width;
    m_height = grid->height;
    m_tilesetTexture = Application::GetInstance().GetTextureRegistry().GetResource(tilesetPath.c_str());

    m_renderState.texture = m_tilesetTexture.GetPointer();
    // Calculate the transform matrix for the grid
    // It is dependent on the camera position and the size of the window (to center the grid)
    /*m_renderState.transform.translate(
        -sf::Vector2f(
            TILE_SIZE * static_cast<float>(m_width),
            TILE_SIZE * static_cast<float>(m_height)
        ) / 2.0f
    );*/

    if(!m_renderTexture.create({
        static_cast<unsigned int>(TILE_SIZE * static_cast<float>(m_width)),
        static_cast<unsigned int>(TILE_SIZE * static_cast<float>(m_height))
    }))
    {
        throw std::runtime_error("Failed to create render texture");
    }

    // Free the grid
    free(grid);
}

bool GameGrid::HandleEvent(const sf::Event &event)
{
    if(event.type == sf::Event::MouseWheelScrolled)
    {
        m_zoomDelta += event.mouseWheelScroll.delta;
        return true;
    }

    return false;
}

void GameGrid::Update(float deltaTime)
{
    for(auto& tile : m_tiles)
    {
        tile->Update(deltaTime, *this, m_player);
    }

    sf::Rect<float> playerBoundingBox = m_player->GetBoundingBox();
    sf::Vector2f playerPosition = m_player->GetPosition();
    float w = static_cast<float>(m_width) * TILE_SIZE / 2.0f;
    float h = static_cast<float>(m_height) * TILE_SIZE / 2.0f;

    if(playerBoundingBox.left < -w)
    {
        playerPosition.x += -w - playerBoundingBox.left;
    }
    else if(playerBoundingBox.left + playerBoundingBox.width > w)
    {
        playerPosition.x += w - playerBoundingBox.width - playerBoundingBox.left;
    }

    if(playerBoundingBox.top < -h)
    {
        playerPosition.y -= playerBoundingBox.top + h;
    }
    else if(playerBoundingBox.top + playerBoundingBox.height > h)
    {
        playerPosition.y -= playerBoundingBox.top + playerBoundingBox.height - h;
    }

    m_player->SetPosition(playerPosition);

    std::vector<std::pair<CollisionInfo, const std::unique_ptr<Tile>*>> collidedTiles;

    for(auto& tile : m_collidableTiles)
    {
        CollisionInfo info = DynamicRectangleCollision(m_player->GetBoundingBox(), (*tile)->GetBoundingBox(), m_player->GetMovement() * deltaTime);

        if(info)
        {
            collidedTiles.emplace_back(info, tile);
        }
    }

    if(!collidedTiles.empty())
    {
        std::sort(collidedTiles.begin(), collidedTiles.end(), [](const auto& a, const auto& b)
        {
            return a.first.penetrationDepth < b.first.penetrationDepth;
        });

        for(auto& pair : collidedTiles)
        {
            CollisionInfo info = pair.first;

            sf::Vector2f movementDelta = info.contactNormal;
            movementDelta.x *= std::abs(m_player->GetMovement().x);
            movementDelta.y *= std::abs(m_player->GetMovement().y);
            movementDelta *= (1.0f - info.penetrationDepth);

            m_player->SetMovementOffset(movementDelta);
        }
    }

    m_zoomFactor += m_zoomDelta * deltaTime * ZOOM_SPEED;
    m_zoomDelta = 0;

    if(m_zoomFactor < Application::ZOOM_FACTOR + 0.5f)
    {
        m_zoomFactor = Application::ZOOM_FACTOR + 0.5f;
    }

    if(m_zoomFactor > Application::ZOOM_FACTOR + 2.0f)
    {
        m_zoomFactor = Application::ZOOM_FACTOR + 2.0f;
    }

    m_renderView = {
        m_player->GetPosition(),
        sf::Vector2f(
            DEFAULT_VIEW_WIDTH,
            DEFAULT_VIEW_WIDTH / Application::GetInstance().GetAspectRatio()
        ) / m_zoomFactor
    };

    m_vertexArray = std::move(CreateVertexArray());
}

void GameGrid::Render(sf::RenderWindow& window)
{
    m_renderTexture.draw(m_vertexArray, m_renderState);
    m_renderTexture.display();
    sf::Sprite sprite(m_renderTexture.getTexture());
    sprite.setPosition(-sf::Vector2f(
            TILE_SIZE * static_cast<float>(m_width),
            TILE_SIZE * static_cast<float>(m_height)
    ) / 2.0f);

    window.setView(m_renderView);
    window.draw(sprite);
}

sf::VertexArray GameGrid::CreateVertexArray()
{
    // A vertex array is a list of structures called vertices.
    // Each vertex contains a position, a color and a texture coordinate
    // The renderer uses these vertices to draw a primitive
    // (a triangle, a line, a point, etc.)
    // Here we create a vertex array that will contain vertices
    // defining triangles
    sf::VertexArray vertexArray(sf::PrimitiveType::Triangles);

    int startX = static_cast<int>((m_renderView.getCenter().x - m_renderView.getSize().x / 2.0f) / TILE_SIZE) - 1;
    int startY = static_cast<int>((m_renderView.getCenter().y - m_renderView.getSize().y / 2.0f) / TILE_SIZE) - 1;
    int endX = static_cast<int>((m_renderView.getCenter().x + m_renderView.getSize().x / 2.0f) / TILE_SIZE) + 1;
    int endY = static_cast<int>((m_renderView.getCenter().y + m_renderView.getSize().y / 2.0f) / TILE_SIZE) + 1;

    for(int y = startY; y < endY; y++)
    {
        for (int x = startX; x < endX; x++)
        {
            auto& tile = GetTile(x, y);

            // Calculate its position in the vertex array
            // We do not apply any transformations here (like the camera position)
            // because the vertex array will be transformed by the renderer
            // in the render function using RenderStates
            sf::Vector2f position(
                (static_cast<float>(x + static_cast<float>(m_width) / 2.0f) * TILE_SIZE),
                (static_cast<float>(y + static_cast<float>(m_height) / 2.0f) * TILE_SIZE)
            );

            for(uint32_t& textureIndex : tile->m_textureIndices)
            {
                // Calculate the texture coordinates of the tile
                // A texture coordinates (u,v) is a pair of numbers
                // that represent which part of the texture is used
                // to draw the tile
                // We do this the same way we did to calculate the
                // position of the tile in the grid
                float tu = static_cast<float>(static_cast<int>(textureIndex * TILE_SIZE) % m_tilesetTexture->getSize().x);
                float tv = std::trunc(static_cast<float>((textureIndex * TILE_SIZE) / m_tilesetTexture->getSize().x)) * TILE_SIZE;

                sf::IntRect textureRect(
                    {static_cast<int>(tu), static_cast<int>(tv)},
                    {static_cast<int>(TILE_SIZE), static_cast<int>(TILE_SIZE)}
                );

                // Add the vertices to the vertex array
                // We need to add draw 2 triangles in a square
                // to draw the tile, so we add 6 vertices
                vertexArray.append(sf::Vertex(
                    position,
                    {static_cast<float>(textureRect.left), static_cast<float>(textureRect.top)}
                ));
                vertexArray.append(sf::Vertex(
                    position + sf::Vector2f(TILE_SIZE, 0),
                    {static_cast<float>(textureRect.left + textureRect.width), static_cast<float>(textureRect.top)}
                ));
                vertexArray.append(sf::Vertex(
                    position + sf::Vector2f(0, TILE_SIZE),
                    {static_cast<float>(textureRect.left), static_cast<float>(textureRect.top + textureRect.height)}
                ));

                vertexArray.append(sf::Vertex(
                    position + sf::Vector2f(TILE_SIZE, 0),
                    {static_cast<float>(textureRect.left + textureRect.width), static_cast<float>(textureRect.top)}
                ));
                vertexArray.append(sf::Vertex(
                    position + sf::Vector2f(TILE_SIZE, TILE_SIZE),
                    {static_cast<float>(textureRect.left + textureRect.width),
                     static_cast<float>(textureRect.top + textureRect.height)}
                ));
                vertexArray.append(sf::Vertex(
                    position + sf::Vector2f(0, TILE_SIZE),
                    {static_cast<float>(textureRect.left), static_cast<float>(textureRect.top + textureRect.height)}
                ));
            }
        }
    }

    return vertexArray;
}

std::unique_ptr<GameGrid::Tile>& GameGrid::GetTile(int x, int y)
{
    x += static_cast<int>(m_width) / 2;
    y += static_cast<int>(m_height) / 2;
    return m_tiles[y * m_width + x];
}

void GameGrid::SetTextureIndexAtTile(int x, int y, uint64_t layer, uint32_t textureIndex)
{
    x += static_cast<int>(m_width) / 2;
    y += static_cast<int>(m_height) / 2;
    m_tiles[y * m_width + x]->m_textureIndices[layer] = textureIndex;
}

struct TileInfo
{
    bool bottom;
    bool left;
    bool right;
    bool top;

    bool bottomLeft;
    bool bottomRight;
    bool topLeft;
    bool topRight;
};

struct Vector2fKey
{
    sf::Vector2f key;

    bool operator==(const Vector2fKey& other) const
    {
        return key.x == other.key.x && key.y == other.key.y;
    }
};

struct Vector2fKeyHasher
{
    std::size_t operator()(const Vector2fKey& key) const
    {
        return ((std::hash<float>()(key.key.x) ^ (std::hash<float>()(key.key.y) << 1)) >> 1);
    }
};

void CheckSurroundings(float x, float y, std::unordered_map<Vector2fKey, TileInfo, Vector2fKeyHasher>& tiles, GameGrid& grid, TileType type)
{
    TileInfo& info = tiles[{{x, y}}];

    if(y+1 < static_cast<float>(grid.GetHeight()) / 2 && grid.GetTile(static_cast<int>(x), static_cast<int>(y)+1)->GetType() == type)
    {
        info.bottom = true;
        if(tiles.find({{x, y+1}}) == tiles.end())
        {
            tiles[{{x, y+1}}] = {};
            CheckSurroundings(x, y+1, tiles, grid, type);
        }

        if(x-1 > -static_cast<float>(grid.GetWidth()) / 2 && grid.GetTile(static_cast<int>(x)-1, static_cast<int>(y)+1)->GetType() == type)
        {
            info.bottomLeft = true;
            if(tiles.find({{x-1, y+1}}) == tiles.end())
            {
                tiles[{{x-1, y+1}}] = {};
                CheckSurroundings(x-1, y+1, tiles, grid, type);
            }
        }

        if(x+1 < static_cast<float>(grid.GetWidth()) / 2 && grid.GetTile(static_cast<int>(x)+1, static_cast<int>(y)+1)->GetType() == type)
        {
            info.bottomRight = true;
            if(tiles.find({{x+1, y+1}}) == tiles.end())
            {
                tiles[{{x+1, y+1}}] = {};
                CheckSurroundings(x+1, y+1, tiles, grid, type);
            }
        }
    }

    if(y-1 > -static_cast<float>(grid.GetHeight()) / 2 && grid.GetTile(static_cast<int>(x), static_cast<int>(y)-1)->GetType() == type)
    {
        info.top = true;
        if(tiles.find({{x, y-1}}) == tiles.end())
        {
            tiles[{{x, y-1}}] = {};
            CheckSurroundings(x, y-1, tiles, grid, type);
        }

        if(x-1 > -static_cast<float>(grid.GetWidth()) / 2 && grid.GetTile(static_cast<int>(x)-1, static_cast<int>(y)-1)->GetType() == type)
        {
            info.topLeft = true;
            if(tiles.find({{x-1, y-1}}) == tiles.end())
            {
                tiles[{{x-1, y-1}}] = {};
                CheckSurroundings(x-1, y-1, tiles, grid, type);
            }
        }

        if(x+1 < static_cast<float>(grid.GetWidth()) / 2 && grid.GetTile(static_cast<int>(x)+1, static_cast<int>(y)-1)->GetType() == type)
        {
            info.topRight = true;
            if(tiles.find({{x+1, y-1}}) == tiles.end())
            {
                tiles[{{x+1, y-1}}] = {};
                CheckSurroundings(x+1, y-1, tiles, grid, type);
            }
        }
    }

    if(x+1 < static_cast<float>(grid.GetWidth()) / 2 && grid.GetTile(static_cast<int>(x)+1, static_cast<int>(y))->GetType() == type)
    {
        info.right = true;
        if(tiles.find({{x+1, y}}) == tiles.end())
        {
            tiles[{{x+1, y}}] = {};
            CheckSurroundings(x+1, y, tiles, grid, type);
        }
    }

    if(x-1 > -static_cast<float>(grid.GetWidth()) / 2 && grid.GetTile(static_cast<int>(x)-1, static_cast<int>(y))->GetType() == type)
    {
        info.left = true;
        if(tiles.find({{x-1, y}}) == tiles.end())
        {
            tiles[{{x-1, y}}] = {};
            CheckSurroundings(x-1, y, tiles, grid, type);
        }
    }
}

void GameGrid::UpdateSoilArea(sf::Vector2f pos)
{
    std::unordered_map<Vector2fKey, TileInfo, Vector2fKeyHasher> tiles;

    tiles[{pos}] = {};

    CheckSurroundings(pos.x, pos.y, tiles, *this, TileType::Soil);

    for(auto& [key, info] : tiles)
    {
        for(auto possibility : SoilTile::TEXTURES)
        {
            if(possibility.top && possibility.top != info.top) continue;
            if(possibility.bottom && possibility.bottom != info.bottom) continue;
            if(possibility.left && possibility.left != info.left) continue;
            if(possibility.right && possibility.right != info.right) continue;

            if(possibility.topLeft && possibility.topLeft != info.topLeft) continue;
            if(possibility.topRight && possibility.topRight != info.topRight) continue;
            if(possibility.bottomLeft && possibility.bottomLeft != info.bottomLeft) continue;
            if(possibility.bottomRight && possibility.bottomRight != info.bottomRight) continue;

            SetTextureIndexAtTile(key.key.x, key.key.y, 1, possibility.textureIndex);
            break;
        }
    }
}
