//
// Created by Killian on 12/04/2023.
//
#include <Application.h>
#include <Tiles.h>
#include "items/Hoe.h"
#include "Player.h"
#include "GameGrid.h"

Hoe::Hoe() : Item(ItemId::HOE)
{
    m_texture = Application::GetInstance().GetTextureRegistry().GetResource("items/hoe.png");
}

void Hoe::OnUse(Player &player)
{
    if(player.GetTileAtPosition()->GetType() == TileType::Soil && ((std::unique_ptr<SoilTile>&)player.GetTileAtPosition())->IsMature())
    {
        auto& tile = (std::unique_ptr<SoilTile>&)player.GetTileAtPosition();
        switch(tile->GetPlantType())
        {
        case SoilTile::PlantType::CARROT:
            player.AddItem(ItemId::CARROT, 2);
            break;

        }
        tile->SetPlant(SoilTile::PlantType::NONE, 0.0f);
    }
    else
    {
        player.TileArea(sf::IntRect{player.GetTilePosition(), {1, 1}});
    }
}

