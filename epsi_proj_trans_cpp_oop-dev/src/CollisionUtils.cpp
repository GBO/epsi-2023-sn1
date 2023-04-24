//
// Created by Killian on 01/04/2023.
//
#include "CollisionUtils.h"

CollisionInfo RayRectangleCollision(const sf::Vector2f& rayOrigin, const sf::Vector2f& rayDirection, const sf::FloatRect& rect)
{
    sf::Vector2f rayDirInv = { 1.0f / rayDirection.x, 1.0f / rayDirection.y };
    float penetrationDepthNearX = (rect.left - rayOrigin.x) * rayDirInv.x;
    float penetrationDepthNearY = (rect.top - rayOrigin.y) * rayDirInv.y;
    float penetrationDepthFarX = (rect.left + rect.width - rayOrigin.x) * rayDirInv.x;
    float penetrationDepthFarY = (rect.top + rect.height - rayOrigin.y) * rayDirInv.y;

    if( std::isnan(penetrationDepthNearX)
     || std::isnan(penetrationDepthNearY)
     || std::isnan(penetrationDepthFarX)
     || std::isnan(penetrationDepthFarY))
    {
        return { false };
    }

    if(penetrationDepthNearX > penetrationDepthFarX)
    {
        std::swap(penetrationDepthNearX, penetrationDepthFarX);
    }

    if(penetrationDepthNearY > penetrationDepthFarY)
    {
        std::swap(penetrationDepthNearY, penetrationDepthFarY);
    }

    if(penetrationDepthNearX > penetrationDepthFarY || penetrationDepthNearY > penetrationDepthFarX)
    {
        return { false };
    }

    float penetrationDepthNear = std::max(penetrationDepthNearX, penetrationDepthNearY);
    float penetrationDepthFar = std::min(penetrationDepthFarX, penetrationDepthFarY);

    if(penetrationDepthFar < 0.0f)
    {
        return { false };
    }

    CollisionInfo info = { true };
    info.penetrationDepth = penetrationDepthNear;
    info.contactPoint = rayOrigin + (rayDirection * penetrationDepthNear);

    if(penetrationDepthNearX > penetrationDepthNearY)
    {
        if(rayDirInv.x < 0)
        {
            info.contactNormal = { 1.0f, 0.0f };
        }
        else
        {
            info.contactNormal = { -1.0f, 0.0f };
        }
    }
    else if (penetrationDepthNearX < penetrationDepthNearY)
    {
        if(rayDirInv.y < 0)
        {
            info.contactNormal = { 0.0f, 1.0f };
        }
        else
        {
            info.contactNormal = { 0.0f, -1.0f };
        }
    }

    return info;
}

CollisionInfo DynamicRectangleCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2, const sf::Vector2f& collisionVector)
{
    if(collisionVector.x == 0.0f && collisionVector.y == 0.0f)
    {
        return { false };
    }

    sf::FloatRect expandedRect2;
    expandedRect2.left = rect2.left - rect1.width / 2;
    expandedRect2.top = rect2.top - rect1.height / 2;
    expandedRect2.width = rect2.width + rect1.width;
    expandedRect2.height = rect2.height + rect1.height;

    CollisionInfo collisionInfo = RayRectangleCollision(rect1.getPosition() + rect1.getSize() / 2.0f, collisionVector, expandedRect2);

    if(collisionInfo.collision && collisionInfo.penetrationDepth >= 0.0f && collisionInfo.penetrationDepth < 1.0f)
    {
        return collisionInfo;
    }

    return { false };
}