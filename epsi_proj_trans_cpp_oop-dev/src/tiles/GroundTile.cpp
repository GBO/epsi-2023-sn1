//
// Created by Killian on 21/03/2023.
//
#include <Tiles.h>

GroundTile::GroundTile(RawGameTile* tile, sf::Vector2f position) :
    Tile(std::vector<uint32_t>(
        reinterpret_cast<uint32_t*>(tile->data),
        reinterpret_cast<uint32_t*>(tile->data) + tile->texturesCount
    ), position, tile->collidable)
{

}

void GroundTile::Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player)
{
    // Todo: create particle when walking on it
}