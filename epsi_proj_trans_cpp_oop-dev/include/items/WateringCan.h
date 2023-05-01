//
// Created by Killian on 12/04/2023.
//

#pragma once

#include "Item.h"

////////////////////////////////////////////////////////////
/// \brief  A watering can item
///
/// This item is used to water a planted seed. This is needed
/// for it to grow.
///
/// \see SoilTile
///
////////////////////////////////////////////////////////////
class WateringCan : public Item
{
public:
    WateringCan();

    void OnUse(Player& player) override;
};