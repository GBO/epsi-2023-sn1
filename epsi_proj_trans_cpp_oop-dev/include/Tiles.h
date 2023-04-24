//
// Created by Killian on 28/03/2023.
//
#pragma once

#include <GameGrid.h>

struct TextureCombination
{
    std::optional<bool> bottom;
    std::optional<bool> top;
    std::optional<bool> left;
    std::optional<bool> right;
    std::optional<bool> bottomLeft;
    std::optional<bool> bottomRight;
    std::optional<bool> topLeft;
    std::optional<bool> topRight;
    uint32_t textureIndex;
};

////////////////////////////////////////////////////////////
/// \brief  A tile that represents ground
///
/// This tile has no special effects.
///
////////////////////////////////////////////////////////////
class GroundTile : public GameGrid::Tile
{
public:
    explicit GroundTile(RawGameTile* tile, sf::Vector2f position);

    void Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player) override;
    [[nodiscard]] inline TileType GetType() const override { return TileType::Ground; }
};

////////////////////////////////////////////////////////////
/// \brief  A tile used to teleport the player
///
/// This tile will teleport the player to another tile or
/// tilemap. This can be used to create doors or portals for
/// exemple.
///
////////////////////////////////////////////////////////////
class PassagePointTile : public GameGrid::Tile
{
public:
    PassagePointTile(RawGameTile* tile, sf::Vector2f position);

    void Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player) override;
    [[nodiscard]] inline TileType GetType() const override { return TileType::PassagePoint; }
};

////////////////////////////////////////////////////////////
/// \brief  A tile that represents a path
///
/// This tile will speed up the player. The NPCs will also
/// prefer to walk on it if possible.
///
////////////////////////////////////////////////////////////
class PathTile : public GameGrid::Tile
{
public:
    explicit PathTile(RawGameTile* tile, sf::Vector2f position);

    void Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player) override;
    [[nodiscard]] inline TileType GetType() const override { return TileType::Path; }
};

////////////////////////////////////////////////////////////
/// \brief  A tile that represents a tileable soil
///
/// This tile will slow down the player, but it is the only tile
/// that lets the player plant things.
///
////////////////////////////////////////////////////////////
class SoilTile : public GameGrid::Tile
{
public:
    enum class PlantType : uint8_t
    {
        NONE = 0,
        CARROT = 1,
        POTATO = 2,
        CHERRY = 3,
        APPLE = 4
    };

    SoilTile(RawGameTile* tile, sf::Vector2f position);
    SoilTile(const std::vector<uint32_t>& textures, sf::Vector2f position, bool collidable);

    void Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player) override;
    [[nodiscard]] inline TileType GetType() const override { return TileType::Soil; }

    [[nodiscard]] inline bool IsMature() const { return m_timeElapsed >= m_fullGrowthTime; }
    [[nodiscard]] inline PlantType GetPlantType() const { return m_plantType; }

    void SetPlant(PlantType type, float fullGrowthTime);
    void Water();

    static constexpr uint32_t TEXTURE_ALL_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_CONNECTED = 47;
    static constexpr uint32_t TEXTURE_BOTTOM_CONNECTED = 45;
    static constexpr uint32_t TEXTURE_LEFT_CONNECTED = 35;
    static constexpr uint32_t TEXTURE_RIGHT_CONNECTED = 33;
    static constexpr uint32_t TEXTURE_NONE_CONNECTED = 32;
    static constexpr uint32_t TEXTURE_BOTTOM_RIGHT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_BOTTOM_LEFT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_RIGHT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_LEFT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_LEFT_RIGHT_CONNECTED = 34;
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_CONNECTED = 46;
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_LEFT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_LEFT_RIGHT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_ALL_CORNERS = 40;
    static constexpr uint32_t TEXTURE_TOP_LEFT_CONNECTED_TOP_LEFT_CORNER = 44;
    static constexpr uint32_t TEXTURE_TOP_RIGHT_CONNECTED_TOP_RIGHT_CORNER = 42;
    static constexpr uint32_t TEXTURE_BOTTOM_RIGHT_CONNECTED_BOTTOM_RIGHT_CORNER = 36;
    static constexpr uint32_t TEXTURE_BOTTOM_LEFT_CONNECTED_BOTTOM_LEFT_CORNER = 38;
    static constexpr uint32_t TEXTURE_TOP_LEFT_RIGHT_CONNECTED_TOP_CORNER = 43;
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED_RIGHT_CORNER = 39;
    static constexpr uint32_t TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED_BOTTOM_CORNER = 37;
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_LEFT_CONNECTED_LEFT_CORNER = 41;
    static constexpr uint32_t TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED_BOTTOM_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED_BOTTOM_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_LEFT_RIGHT_CONNECTED_TOP_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_LEFT_RIGHT_CONNECTED_TOP_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED_TOP_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED_TOP_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_LEFT_CONNECTED_TOP_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_TOP_BOTTOM_LEFT_CONNECTED_TOP_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_BOTTOM_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_TOP_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_TOP_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_TOP_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_BOTTOM_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_BOTTOM_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_EXCEPT_TOP_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_EXCEPT_TOP_LEFT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_EXCEPT_BOTTOM_RIGHT_CORNER = 43; // TODO
    static constexpr uint32_t TEXTURE_ALL_CONNECTED_EXCEPT_BOTTOM_LEFT_CORNER = 43; // TODO

    static constexpr uint32_t TEXTURE_WET_TILED_SOIL = 64;

    static constexpr TextureCombination TEXTURES[45] = {
        {false, false, false, false, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_NONE_CONNECTED},
        {false, false, true, false, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_LEFT_CONNECTED},
        {false, false, false, true, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_RIGHT_CONNECTED},
        {false, true, false, false, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_TOP_CONNECTED},
        {true, false, false, false, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_CONNECTED},
        {true, false, false, true, std::nullopt, false, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_RIGHT_CONNECTED},
        {true, false, true, false, false, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_LEFT_CONNECTED},
        {false, true, false, true, std::nullopt, std::nullopt, std::nullopt, false, SoilTile::TEXTURE_TOP_RIGHT_CONNECTED},
        {false, true, true, false, std::nullopt, std::nullopt, false, std::nullopt, SoilTile::TEXTURE_TOP_LEFT_CONNECTED},
        {false, false, true, true, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_LEFT_RIGHT_CONNECTED},
        {true, true, false, false, std::nullopt, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_TOP_BOTTOM_CONNECTED},
        {true, true, false, true, std::nullopt, false, std::nullopt, false, SoilTile::TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED},
        {true, true, true, false, false, std::nullopt, false, std::nullopt, SoilTile::TEXTURE_TOP_BOTTOM_LEFT_CONNECTED},
        {false, true, true, true, std::nullopt, std::nullopt, false, false, SoilTile::TEXTURE_TOP_LEFT_RIGHT_CONNECTED},
        {true, false, true, true, false, false, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED},
        {true, true, true, true, false, false, false, false, SoilTile::TEXTURE_ALL_CONNECTED},
        {true, true, true, true, true, true, true, true, SoilTile::TEXTURE_ALL_CONNECTED_ALL_CORNERS},
        {false, true, true, false, std::nullopt, std::nullopt, true, std::nullopt, SoilTile::TEXTURE_TOP_LEFT_CONNECTED_TOP_LEFT_CORNER},
        {false, true, false, true, std::nullopt, std::nullopt, std::nullopt, true, SoilTile::TEXTURE_TOP_RIGHT_CONNECTED_TOP_RIGHT_CORNER},
        {true, false, false, true, std::nullopt, true, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_RIGHT_CONNECTED_BOTTOM_RIGHT_CORNER},
        {true, false, true, false, true, std::nullopt, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_LEFT_CONNECTED_BOTTOM_LEFT_CORNER},
        {false, true, true, true, std::nullopt, std::nullopt, true, true, SoilTile::TEXTURE_TOP_LEFT_RIGHT_CONNECTED_TOP_CORNER},
        {true, true, false, true, std::nullopt, true, std::nullopt, true, SoilTile::TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED_RIGHT_CORNER},
        {true, false, true, true, true, true, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED_BOTTOM_CORNER},
        {true, true, true, false, true, std::nullopt, true, std::nullopt, SoilTile::TEXTURE_TOP_BOTTOM_LEFT_CONNECTED_LEFT_CORNER},
        {true, false, true, true, true, false, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED_BOTTOM_LEFT_CORNER},
        {true, false, true, true, false, true, std::nullopt, std::nullopt, SoilTile::TEXTURE_BOTTOM_LEFT_RIGHT_CONNECTED_BOTTOM_RIGHT_CORNER},
        {false, true, true, true, std::nullopt, std::nullopt, false, true, SoilTile::TEXTURE_TOP_LEFT_RIGHT_CONNECTED_TOP_RIGHT_CORNER},
        {false, true, true, true, std::nullopt, std::nullopt, true, false, SoilTile::TEXTURE_TOP_LEFT_RIGHT_CONNECTED_TOP_LEFT_CORNER},
        {true, true, false, true, std::nullopt, true, std::nullopt, false, SoilTile::TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED_TOP_RIGHT_CORNER},
        {true, true, false, true, std::nullopt, false, std::nullopt, true, SoilTile::TEXTURE_TOP_BOTTOM_RIGHT_CONNECTED_TOP_LEFT_CORNER},
        {true, true, true, false, true, std::nullopt, false, std::nullopt, SoilTile::TEXTURE_TOP_BOTTOM_LEFT_CONNECTED_TOP_LEFT_CORNER},
        {true, true, true, false, false, std::nullopt, true, std::nullopt, SoilTile::TEXTURE_TOP_BOTTOM_LEFT_CONNECTED_TOP_RIGHT_CORNER},
        {true, true, true, true, true, true, false, false, SoilTile::TEXTURE_ALL_CONNECTED_BOTTOM_CORNER},
        {true, true, true, true, false, true, false, true, SoilTile::TEXTURE_ALL_CONNECTED_RIGHT_CORNER},
        {true, true, true, true, false, false, true, true, SoilTile::TEXTURE_ALL_CONNECTED_TOP_CORNER},
        {true, true, true, true, true, false, true, false, SoilTile::TEXTURE_ALL_CONNECTED_LEFT_CORNER},
        {true, true, true, true, false, false, false, true, SoilTile::TEXTURE_ALL_CONNECTED_TOP_RIGHT_CORNER},
        {true, true, true, true, false, false, true, false, SoilTile::TEXTURE_ALL_CONNECTED_TOP_LEFT_CORNER},
        {true, true, true, true, true, false, false, false, SoilTile::TEXTURE_ALL_CONNECTED_BOTTOM_RIGHT_CORNER},
        {true, true, true, true, false, true, false, false, SoilTile::TEXTURE_ALL_CONNECTED_BOTTOM_LEFT_CORNER},
        {true, true, true, true, true, true, true, false, SoilTile::TEXTURE_ALL_CONNECTED_EXCEPT_TOP_RIGHT_CORNER},
        {true, true, true, true, true, true, false, true, SoilTile::TEXTURE_ALL_CONNECTED_EXCEPT_TOP_LEFT_CORNER},
        {true, true, true, true, true, false, true, true, SoilTile::TEXTURE_ALL_CONNECTED_EXCEPT_BOTTOM_RIGHT_CORNER},
        {true, true, true, true, false, true, true, true, SoilTile::TEXTURE_ALL_CONNECTED_EXCEPT_BOTTOM_LEFT_CORNER},
    };

private:
    PlantType m_plantType;
    bool m_isWatered = false;
    float m_timeElapsed = 0;
    float m_fullGrowthTime = 0;

    static constexpr uint32_t PLANT_TEXTURES[][2] = {
        {0, 0},
        {96, 97},
        {98, 99},
        {100, 101},
        {102, 103}
    };
};