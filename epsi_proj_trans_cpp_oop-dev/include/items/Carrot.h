//
// Created by Killian on 12/04/2023.
//

#pragma once

#include "Item.h"

////////////////////////////////////////////////////////////
/// \brief  A carrot item
///
/// This item is currently used as a seed. The player needs
/// to use it on a tiled soil, and water it for the plant to
/// grow.
///
/// \see SoilTile
/// \see WateringCan
///
////////////////////////////////////////////////////////////
class Carrot : public Item
{
public:
    Carrot();

    void OnUse(Player& player) override;
};