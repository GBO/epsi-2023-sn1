//
// Created by Alban on 31/03/2023.
//

#pragma once

#include <GameObject.h>
#include "ResourceRegistry.h"
#include "Item.h"

////////////////////////////////////////////////////////////////////////////
/// \brief  The inventory of the player
///
/// This object is a GUI object used to store and render items picked up by
/// the player
///
/// \see GameObject
/// \see Item
///
////////////////////////////////////////////////////////////////////////////
class Inventory : public GameObject
{
public:
    void Init() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
    bool HandleEvent(const sf::Event& event) override;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Sets an item at a given slot
    ///
    /// If the slot needs to be cleared, item must be nullptr.
    /// If the slot index can be anything, index must be -1. This will place the
    /// item in the first free slot
    ///
    /// \param item the item to be set, or nullptr to clear the slot
    /// \param index the index of the slot to be set, or -1 to set the first free slot
    /// \return true if the item was set, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////
    bool SetItem(Item* item, int index = -1);

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Gets an item at a given slot
    ///
    /// \param index the index of the sot
    /// \return the item at the given slot, or nullptr if the slot is empty
    ///
    ////////////////////////////////////////////////////////////////////////////
    [[nodiscard]] inline Item* GetItem(int index) const { return m_items[index]; }

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Gets the hovered item
    ///
    /// \return the hovered item
    ///
    ////////////////////////////////////////////////////////////////////////////
    [[nodiscard]] inline Item* GetHoveredItem() const { return (m_slotHovered != -1) ? m_items[m_slotHovered] : nullptr; }

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Gets the index of the hovered slot
    ///
    /// \return the hovered slot index, or -1 if no slot is hovered
    ///
    ////////////////////////////////////////////////////////////////////////////
    [[nodiscard]] inline int GetHoveredSlot() const { return m_slotHovered; }

    static constexpr int HOTBAR_SLOT_COUNT = 10;
    static constexpr int INVENTORY_ROWS = 3;
    static constexpr int INVENTORY_COLUMNS = 10;
    static constexpr int INVENTORY_SLOT_COUNT = INVENTORY_ROWS * INVENTORY_COLUMNS;
    static constexpr int TOTAL_SLOT_COUNT = HOTBAR_SLOT_COUNT + INVENTORY_SLOT_COUNT;

    static constexpr float INVENTORY_WINDOW_WIDTH_PERCENTAGE = 0.8f; // 0-1
    static constexpr float INVENTORY_WINDOW_HEIGHT_PERCENTAGE = 0.8f; // 0-1
    static constexpr int INVENTORY_OFFSET = 10;
    static constexpr int INVENTORY_SLOT_MARGIN = 5;
    static constexpr int INVENTORY_SLOT_SIZE = 32;

private:
    ////////////////////////////////////////////////////////////////////////////
    /// \brief  Finds the next free slot in the inventory and updates
    ///         m_firstFreeSlot
    ///
    ////////////////////////////////////////////////////////////////////////////
    void FindNextFreeSlot();

    ////////////////////////////////////////////////////////////////////////////
    /// \brief  An internal function used when the inventory needs to be resized
    ///
    /// This function will compute the size and position of the inventory and its
    /// components, based on the window size.
    ///
    ////////////////////////////////////////////////////////////////////////////
    void Resize();

    TextureRegistry::ResourceHandle m_texture;
    sf::Sprite m_inventory;

    TextureRegistry::ResourceHandle m_slotHoveredTexture;
    sf::Sprite m_slotHoveredSprite;

    std::mutex m_mutex;
    Item* m_items[TOTAL_SLOT_COUNT] = {nullptr};

    int m_firstFreeSlot = 0;
    bool m_isOpen = false;
    int m_slotHovered = -1;
    int m_slotInHand = -1;

    float m_slotSize;
    sf::Vector2f m_inventorySize;
    float m_computedOffset;
    float m_computedMargin;
};
