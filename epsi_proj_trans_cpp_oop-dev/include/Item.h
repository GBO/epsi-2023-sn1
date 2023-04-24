//
// Created by Alban on 31/03/2023.
//
#pragma once

#include <GameObject.h>
#include "ResourceRegistry.h"

// The ID of an item
enum ItemId : uint16_t
{
    HOE,
    WATERING_CAN,
    CARROT
};

////////////////////////////////////////////////////////////////////////////
/// \brief  A base class for an item stored in the player's inventory
///
///
////////////////////////////////////////////////////////////////////////////
class Item
{
public:
    [[nodiscard]] inline std::string GetName() const { return m_name; }
    [[nodiscard]] inline int GetStackSize() const { return m_stackSize; }
    [[nodiscard]] inline int GetCount() const { return m_count; }
    [[nodiscard]] inline ItemId GetId() const { return m_id; }

    inline void Add(int count) { m_count += count; }

    virtual void OnUse(class Player& player) = 0;

protected:
    friend class Inventory;
    friend class Hotbar;

    explicit Item(ItemId id) : m_id(id) {}

    ItemId m_id;
    std::string m_name;
    int m_stackSize = 1;
    int m_count = 1;
    TextureRegistry::ResourceHandle m_texture;
};



