//
// Created by Killian on 12/04/2023.
//
#include <Application.h>
#include <Tiles.h>
#include "items/Carrot.h"
#include "Player.h"
#include "GameGrid.h"

Carrot::Carrot() : Item(ItemId::CARROT)
{
    m_stackSize = 64;
    m_texture = Application::GetInstance().GetTextureRegistry().GetResource("items/carrot.png");
}

void Carrot::OnUse(Player &player)
{
    if(player.GetTileAtPosition()->GetType() == TileType::Soil
    && ((std::unique_ptr<SoilTile>&)player.GetTileAtPosition())->GetPlantType() == SoilTile::PlantType::NONE)
    {
        auto& tile = (std::unique_ptr<SoilTile>&)player.GetTileAtPosition();
        tile->SetPlant(SoilTile::PlantType::CARROT, 10.0f);

        m_count--;
        if(m_count <= 0)
            player.RemoveItem(this);
    }
}

