//
// Created by Killian on 28/03/2023.
//
#include <Tiles.h>

SoilTile::SoilTile(RawGameTile* tile, sf::Vector2f position) :
        SoilTile(std::vector<uint32_t>(
                reinterpret_cast<uint32_t*>(tile->data),
                reinterpret_cast<uint32_t*>(tile->data) + tile->texturesCount
        ), position, tile->collidable)
{
    if( tile->size != sizeof(RawGameTile)
        + sizeof(uint32_t) * tile->texturesCount
        + sizeof(uint8_t)
        + sizeof(bool)
        + sizeof(float)) {
        throw std::runtime_error("Invalid tile size");
    }

    m_plantType = static_cast<PlantType>(tile->data[tile->texturesCount * sizeof(uint32_t)]);
    m_isWatered = tile->data[tile->texturesCount * sizeof(uint32_t) + 1];
    memcpy(&m_fullGrowthTime, &tile->data[tile->texturesCount * sizeof(uint32_t) + 2], sizeof(float));
    if(m_plantType != PlantType::NONE)
    {
        m_textureIndices.push_back(PLANT_TEXTURES[(uint64_t) m_plantType][0]);
    }
}

SoilTile::SoilTile(const std::vector<uint32_t> &textures, sf::Vector2f position, bool collidable)
    : Tile(textures, position, collidable)
{
    m_plantType = PlantType::NONE;
    m_isWatered = false;
    m_fullGrowthTime = 0;
}

void SoilTile::Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player)
{
    if(m_plantType != PlantType::NONE)
    {
        if (m_isWatered)
        {
            m_timeElapsed += deltaTime;
        }

        if (m_timeElapsed >= m_fullGrowthTime)
        {
            m_textureIndices[m_textureIndices.size() - 1] = PLANT_TEXTURES[(uint64_t) m_plantType][1];
        }
    }
}

void SoilTile::SetPlant(PlantType type, float fullGrowthTime)
{
    m_plantType = type;
    m_fullGrowthTime = fullGrowthTime;
    m_isWatered = false;
    m_timeElapsed = 0;
    if(m_textureIndices.size() > 2) m_textureIndices.erase(m_textureIndices.begin() + 2, m_textureIndices.end());
    if(m_plantType != PlantType::NONE) m_textureIndices.push_back(PLANT_TEXTURES[(uint64_t) m_plantType][0]);
}

void SoilTile::Water()
{
    m_isWatered = true;
    m_textureIndices.insert(m_textureIndices.end() - 1, TEXTURE_WET_TILED_SOIL);
}