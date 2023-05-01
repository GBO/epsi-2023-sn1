//
// Created by Killian on 10/04/2023.
//
#include <Item.h>
#include "Hotbar.h"
#include "Application.h"

void Hotbar::Init()
{
#ifdef DEBUG
    if(!m_inventory) throw std::runtime_error("Hotbar::Init() : m_inventory is null");
#endif

    m_hotbarTexture = Application::GetInstance().GetTextureRegistry().GetResource("gui/hotbar.png");
    m_hotbarSlotSelectedTexture = Application::GetInstance().GetTextureRegistry().GetResource("gui/slot.png");

    m_hotbarSprite.setTexture(m_hotbarTexture);
    m_hotbarSlotSelectedSprite.setTexture(m_hotbarSlotSelectedTexture);
    Resize();
}

void Hotbar::Update(float deltaTime)
{
    m_hotbarSlotSelectedSprite.setPosition({
        m_hotbarSprite.getPosition().x + m_computedOffset + m_selectedSlot * (m_slotSize + m_computedMargin),
        m_hotbarSprite.getPosition().y + m_computedOffset
    });
}

void Hotbar::Render(sf::RenderWindow& window)
{
    window.draw(m_hotbarSprite);
    window.draw(m_hotbarSlotSelectedSprite);

    for(int i = 0; i < Inventory::HOTBAR_SLOT_COUNT; ++i)
    {
        Item* item = m_inventory->GetItem(Inventory::INVENTORY_SLOT_COUNT + i);
        if(item != nullptr)
        {
            sf::Sprite itemSprite = sf::Sprite(item->m_texture);
            itemSprite.setPosition({
               m_hotbarSprite.getPosition().x + m_computedOffset + i * (m_slotSize + m_computedMargin),
                m_hotbarSprite.getPosition().y + m_computedOffset
            });

            itemSprite.setScale({
                m_slotSize / itemSprite.getTexture()->getSize().x,
                m_slotSize / itemSprite.getTexture()->getSize().y
            });

            window.draw(itemSprite);
        }
    }
}

bool Hotbar::HandleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num9)
        {
            SelectSlot(event.key.code - sf::Keyboard::Num1);
            return true;
        }
        else if(event.key.code == sf::Keyboard::Num0)
        {
            SelectSlot(9);
            return true;
        }
    }
    else if(event.type == sf::Event::Resized)
    {
        Resize();
    }
    return false;
}

void Hotbar::SelectSlot(int slot)
{

    if(m_inventory->GetHoveredSlot() != -1)
    {
        Item* item = m_inventory->GetHoveredItem();
        Item* currentItem = m_inventory->GetItem(Inventory::INVENTORY_SLOT_COUNT + slot);
        m_inventory->SetItem(item, Inventory::INVENTORY_SLOT_COUNT + slot);
        m_inventory->SetItem(currentItem, m_inventory->GetHoveredSlot());
    }
    else
    {
        m_selectedSlot = slot;
    }
}

void Hotbar::Resize()
{
    sf::Vector2f computedSize = {
        static_cast<float>(Application::GetInstance().GetWindowWidth()) * HOTBAR_WINDOW_WIDTH_PERCENTAGE,
        static_cast<float>(Application::GetInstance().GetWindowHeight()) * HOTBAR_WINDOW_HEIGHT_PERCENTAGE
    };

    sf::Vector2f computedScale = {
        computedSize.x / m_hotbarTexture->getSize().x,
        computedSize.y / m_hotbarTexture->getSize().y
    };

    sf::Vector2f offset = {
        HOTBAR_OFFSET * computedScale.x * 2,
        HOTBAR_OFFSET * computedScale.y * 2
    };

    float margin = HOTBAR_SLOT_MARGIN * computedScale.x * (Inventory::HOTBAR_SLOT_COUNT - 1);

    sf::Vector2f totalSlotSize = {
        computedSize.x - (offset.x + margin),
        computedSize.y - offset.y
    };

    sf::Vector2f slotSize = {
        totalSlotSize.x / Inventory::HOTBAR_SLOT_COUNT,
        totalSlotSize.y
    };

    m_slotSize = std::min(slotSize.x, slotSize.y);
    float finalScale = m_slotSize / HOTBAR_SLOT_SIZE;
    m_computedMargin = HOTBAR_SLOT_MARGIN * finalScale;
    m_computedOffset = HOTBAR_OFFSET * finalScale;

    m_hotbarSize = {
        m_slotSize * Inventory::HOTBAR_SLOT_COUNT + m_computedOffset * 2 + m_computedMargin * (Inventory::HOTBAR_SLOT_COUNT - 1),
        m_slotSize + m_computedOffset * 2
    };

    m_hotbarSprite.setScale({
        m_hotbarSize.x / m_hotbarTexture->getSize().x,
        m_hotbarSize.y / m_hotbarTexture->getSize().y
    });

    m_hotbarSprite.setPosition({
        Application::GetInstance().GetWindowWidth() / 2 - m_hotbarSize.x / 2,
        Application::GetInstance().GetWindowHeight() - m_hotbarSize.y
    });

    m_hotbarSlotSelectedSprite.setScale({
         finalScale,
         finalScale
    });
}

void Hotbar::UseSelected(Player& player)
{
    Item* item = m_inventory->GetItem(Inventory::INVENTORY_SLOT_COUNT + m_selectedSlot);
    if(item != nullptr) item->OnUse(player);
}