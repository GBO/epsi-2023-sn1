//
// Created by Alban on 30/03/2023.
//
#pragma once

#include <GameObject.h>

#include <utility>
#include "ResourceRegistry.h"
#include "Inventory.h"
#include "Hotbar.h"
#include "GameGrid.h"

class GameGrid;

// The orientation of the player
enum Orientation : int {
    UP = 1,
    RIGHT = 2,
    DOWN = 0,
    LEFT = 3
};

////////////////////////////////////////////////////////////////////////////
/// \brief  The player object
///
/// This object stores and control the player state.
///
////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
public:
    void Init() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
    [[nodiscard]] bool HandleEvent(const sf::Event& event) override;

    inline void SetPosition(sf::Vector2f position) { m_position = position; }
    inline void SetMovementOffset(sf::Vector2f movement) { m_movementOffset = movement; }

    inline void SetGameGrid(std::shared_ptr<GameGrid> gameGrid) { m_gameGrid = std::move(gameGrid); }
    inline void SetHotbar(std::shared_ptr<Hotbar> hotbar) { m_hotbar = std::move(hotbar); }
    inline void SetInventory(std::shared_ptr<Inventory> inventory) { m_inventory = std::move(inventory); }

    void AddItem(ItemId id, int count = 1);
    void RemoveItem(Item* item);

    [[nodiscard]] inline sf::Vector2f GetPosition() const { return m_position; }
    [[nodiscard]] sf::Vector2i GetTilePosition() const;
    [[nodiscard]] inline sf::Vector2f GetMovement() const { return m_movement; }
    [[nodiscard]] sf::Rect<float> GetBoundingBox() const;
    [[nodiscard]] std::unique_ptr<GameGrid::Tile>& GetTileAtPosition() const;

    void TileArea(sf::IntRect area);

private:
    static constexpr float ANIMATION_DELAY = 0.1f;
    static constexpr int ANIMATION_FRAME_COUNT = 6;
    static constexpr int WIDTH = 32;
    static constexpr int HEIGHT = 64;
    static constexpr float WALK_SPEED = 2.0f;
    static constexpr float SPRINT_SPEED = 8.0f;
    static constexpr float ITEM_COOLDOWN = 1.0f;

    Orientation m_orientation = DOWN;
    float m_animationTimer = 0.0f;
    bool m_isMoving = false;

    sf::Vector2f m_movement;
    sf::Vector2f m_movementNorm;
    sf::Vector2f m_movementOffset;
    sf::Vector2f m_position;

    TextureRegistry::ResourceHandle m_texture;
    sf::Sprite m_sprite;

    std::shared_ptr<GameGrid> m_gameGrid;
    std::shared_ptr<Hotbar> m_hotbar;
    std::shared_ptr<Inventory> m_inventory;

    bool m_shouldUseItem = false;
    float m_itemCooldown = 0;

    void DoAnimation(int index, float timer);
};