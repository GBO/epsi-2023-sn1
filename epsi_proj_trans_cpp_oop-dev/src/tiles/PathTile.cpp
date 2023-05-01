//
// Created by Killian on 28/03/2023.
//
#include <Tiles.h>

PathTile::PathTile(RawGameTile* tile, sf::Vector2f position) :
        Tile(std::vector<uint32_t>(
                reinterpret_cast<uint32_t*>(tile->data),
                reinterpret_cast<uint32_t*>(tile->data) + tile->texturesCount
        ), position, tile->collidable)
{

}

void PathTile::Update(float deltaTime, GameGrid& grid, const std::shared_ptr<Player>& player)
{

}