//
// Created by Killian on 12/04/2023.
//

#pragma once

#include "Item.h"

////////////////////////////////////////////////////////////
/// \brief  A hoe item
///
/// This tool is used to transform a ground tile into a tiled
/// soil tile, as well as picking up mature plants.
///
/// \see SoilTile
///
////////////////////////////////////////////////////////////
class Hoe : public Item
{
public:
    Hoe();

    void OnUse(Player& player) override;
};