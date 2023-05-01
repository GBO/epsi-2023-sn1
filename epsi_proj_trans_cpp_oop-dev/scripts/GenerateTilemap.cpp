#include <cstdint>
#include <string>
#include <fstream>
#include <vector>

enum class TileType : uint8_t
{
    Ground = 0,
    PassagePoint = 1,
    Path = 2,
    Soil = 3
};

enum class TextureIndices : uint32_t
{
    GRASS_1 = 0,
    GRASS_2 = 1,
    GRASS_3 = 2,
    GRASS_4 = 3,

    TILED_SOIL_NONE_CONNECTED = 32,
    TILED_SOIL_RIGHT_CONNECTED = 33,
    TILED_SOIL_LEFT_RIGHT_CONNECTED = 34,
    TILED_SOIL_LEFT_CONNECTED = 35,
    TILED_SOIL_RIGHT_BOTTOM_CONNECTED_BOTTOM_RIGHT_CORNER = 36,
    TILED_SOIL_RIGHT_LEFT_BOTTOM_CONNECTED_BOTTOM_CORNER = 37,
    TILED_SOIL_LEFT_BOTTOM_CONNECTED_BOTTOM_LEFT_CORNER = 38,
    TILED_SOIL_RIGHT_TOP_BOTTOM_CONNECTED_RIGHT_CORNER = 39,
    TILED_SOIL_ALL_CONNECTED_ALL_CORNER = 40,
    TILED_SOIL_LEFT_TOP_BOTTOM_CONNECTED_LEFT_CORNER = 41,
    TILED_SOIL_RIGHT_TOP_CONNECTED_TOP_RIGHT_CORNER = 42,
    TILED_SOIL_RIGHT_LEFT_TOP_CONNECTED_TOP_CORNER = 43,
    TILED_SOIL_LEFT_TOP_CONNECTED_TOP_LEFT_CORNER = 44,
    TILED_SOIL_BOTTOM_CONNECTED = 45,
    TILED_SOIL_TOP_BOTTOM_CONNECTED = 46,
    TILED_SOIL_TOP_CONNECTED = 47,

    WET_TILED_SOIL = 64,
};

#pragma pack(push, 1)
struct RawGameGrid
{
    uint32_t width;
    uint32_t height;
    uint32_t tilesetPathSize; // size of the tilemaps path
    uint32_t tilesSize; // total size of tiles
    uint32_t entitiesSize; // total size of entities
    uint8_t data[];
};

// The tile structure in the file
struct RawGameTile
{
    TileType type;
    uint32_t size; // size of total structure
    uint32_t textureCount; // number of textures
    bool collidable;
    uint8_t data[]; // custom data
};

// The entity structure in the file (TODO)
struct RawGameEntity
{
    uint32_t size; // size of total structure
    uint32_t textureIndex; // offset in texture names
    uint8_t data[]; // custom data
};
#pragma pack(pop)

class Tile
{
public:
    explicit Tile(const std::vector<uint32_t>& textureIndices, bool collidable) : m_textureIndices(textureIndices), m_collidable(collidable) {}
    virtual ~Tile() = default;

    virtual RawGameTile* Serialize() = 0;

    std::vector<uint32_t> m_textureIndices;
    bool m_collidable;
};


class GroundTile : public Tile
{
public:
    explicit GroundTile(const std::vector<uint32_t>& textureIndices, bool collidable) : Tile(textureIndices, collidable) {}

    RawGameTile* Serialize() override
    {
        uint32_t size = sizeof(RawGameTile) + sizeof(uint32_t) * m_textureIndices.size();
        auto* tile = (RawGameTile*)malloc(size);
        tile->type = TileType::Ground;
        tile->size = size;
        tile->textureCount = m_textureIndices.size();
        tile->collidable = m_collidable;
        memcpy(tile->data, m_textureIndices.data(), sizeof(uint32_t) * m_textureIndices.size());
        return tile;
    }
};

class PassagePointTile : public Tile
{
public:
    PassagePointTile(const std::vector<uint32_t>& textureIndices, bool collidable, std::string tilemap, std::pair<uint32_t, uint32_t> position)
            : Tile(textureIndices, collidable), m_tilemap(tilemap), m_position(position) {}

    RawGameTile* Serialize() override
    {
        uint64_t size = sizeof(RawGameTile) + m_tilemap.size() + sizeof(uint64_t) * 3 + sizeof(uint32_t) * m_textureIndices.size();
        auto* tile = (RawGameTile*)malloc(size);
        tile->type = TileType::PassagePoint;
        tile->size = size;
        tile->textureCount = m_textureIndices.size();
        tile->collidable = m_collidable;
        memcpy(tile->data, m_textureIndices.data(), sizeof(uint32_t) * m_textureIndices.size());
        tile->data[m_textureIndices.size() * sizeof(uint32_t)] = m_tilemap.size();
        memcpy(tile->data + m_textureIndices.size() * sizeof(uint32_t) + 1, m_tilemap.c_str(), m_tilemap.size());
        tile->data[m_tilemap.size() + m_textureIndices.size() * sizeof(uint32_t) + 1] = m_position.first;
        tile->data[m_tilemap.size() + m_textureIndices.size() * sizeof(uint32_t) + 2] = m_position.second;
        return tile;
    }

private:
    std::string m_tilemap;
    std::pair<uint64_t, uint64_t> m_position;
};

class PathTile : public Tile
{
public:
    explicit PathTile(const std::vector<uint32_t>& textureIndices, bool collidable) : Tile(textureIndices, collidable) {}

    RawGameTile* Serialize() override
    {
        uint32_t size = sizeof(RawGameTile) + sizeof(uint32_t) * m_textureIndices.size();
        auto* tile = (RawGameTile*)malloc(size);
        tile->type = TileType::Path;
        tile->size = size;
        tile->textureCount = m_textureIndices.size();
        tile->collidable = m_collidable;
        memcpy(tile->data, m_textureIndices.data(), sizeof(uint32_t) * m_textureIndices.size());
        return tile;
    }
};

enum class PlantType : uint8_t
{
    NONE = 0,
    CARROT = 1,
    POTATO = 2,
    CHERRY = 3,
    APPLE = 4
};

class SoilTile : public Tile
{
public:
    // TODO: support plants
    SoilTile(const std::vector<uint32_t>& textureIndices, bool collidable, PlantType type, bool isWatered, float fullGrowthTime) : Tile(textureIndices, collidable), m_plantType(type), m_isWatered(isWatered), m_fullGrowthTime(fullGrowthTime) {}

    RawGameTile* Serialize() override
    {
        uint32_t size = sizeof(RawGameTile) + sizeof(uint32_t) * m_textureIndices.size() + sizeof(uint8_t) + sizeof(bool) + sizeof(float);
        auto* tile = (RawGameTile*)malloc(size);
        tile->type = TileType::Soil;
        tile->size = size;
        tile->textureCount = m_textureIndices.size();
        tile->collidable = m_collidable;
        memcpy(tile->data, m_textureIndices.data(), sizeof(uint32_t) * m_textureIndices.size());
        tile->data[m_textureIndices.size() * sizeof(uint32_t)] = (uint8_t)m_plantType;
        tile->data[m_textureIndices.size() * sizeof(uint32_t) + 1] = m_isWatered;
        memcpy(tile->data + m_textureIndices.size() * sizeof(uint32_t) + 2, &m_fullGrowthTime, sizeof(float));
        return tile;
    }

    PlantType m_plantType;
    bool m_isWatered = false;
    float m_fullGrowthTime = 0;
};

std::pair<uint64_t, uint8_t*> SerializeTilemap(const std::string& tilesetPath, Tile* tilemap[], uint32_t width, uint32_t height)
{
    uint32_t tilesetPathSize = tilesetPath.size();
    uint32_t tilesSize = 0;
    uint32_t entitiesSize = 0;
    for(uint32_t i = 0; i < width * height; i++)
    {
        tilesSize += tilemap[i]->Serialize()->size;
    }

    uint32_t size = sizeof(RawGameGrid) + tilesetPathSize + tilesSize + entitiesSize;
    auto* grid = (RawGameGrid*)malloc(size);
    grid->width = width;
    grid->height = height;
    grid->tilesetPathSize = tilesetPathSize;
    grid->tilesSize = tilesSize;
    grid->entitiesSize = entitiesSize;
    memcpy(grid->data, tilesetPath.c_str(), tilesetPathSize);
    uint32_t offset = tilesetPathSize;
    for(uint32_t i = 0; i < width * height; i++)
    {
        RawGameTile* tile = tilemap[i]->Serialize();
        memcpy(grid->data + offset, tile, tile->size);
        offset += tile->size;
        delete tile;
    }

    return {size, (uint8_t*)grid};
}

int main(int argc, char** argv)
{
    std::string outPath = "tilemap.htf";
    if(argc > 1)
    {
        outPath = argv[1];
    }

    srand(time(NULL));
    Tile* tilemap[250*250];
    for(Tile*& tile : tilemap)
    {
        uint32_t random = rand() % ((uint32_t)TextureIndices::GRASS_4 - (uint32_t)TextureIndices::GRASS_1 + 1) + (uint32_t)TextureIndices::GRASS_1;
        tile = new GroundTile({random}, false);
    }

    delete tilemap[125 + 126 * 250];
    tilemap[125 + 126 * 250] = new SoilTile({(uint32_t)TextureIndices::GRASS_1, (uint32_t)TextureIndices::TILED_SOIL_NONE_CONNECTED, (uint32_t)TextureIndices::WET_TILED_SOIL}, false, PlantType::CARROT, true, 10.0f);

    auto [size, data] = SerializeTilemap("tileset.png", tilemap, 250, 250);
    std::ofstream file(outPath, std::ios::binary);
    file.write((char*)data, size);
}