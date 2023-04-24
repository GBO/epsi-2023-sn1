//
// Created by Killian on 12/04/2023.
//
#include <Application.h>
#include <Tiles.h>
#include "items/WateringCan.h"
#include "Player.h"
#include "GameGrid.h"

WateringCan::WateringCan() : Item(ItemId::HOE)
{
    m_texture = Application::GetInstance().GetTextureRegistry().GetResource("items/watering_can.png");
}

void WateringCan::OnUse(Player &player)
{
    if(player.GetTileAtPosition()->GetType() == TileType::Soil)
    {
        ((std::unique_ptr<SoilTile>&)player.GetTileAtPosition())->Water();
    }
}