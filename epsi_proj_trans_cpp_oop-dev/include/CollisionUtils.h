//
// Created by Killian on 01/04/2023.
//

#pragma once

// A structure containing information about a collision
struct CollisionInfo
{
    bool collision = false;
    sf::Vector2f contactPoint = { 0.0f, 0.0f };
    sf::Vector2f contactNormal = { 0.0f, 0.0f };
    float penetrationDepth = 0.0f;

    [[nodiscard]] explicit operator bool() const
    {
        return collision;
    }
};

////////////////////////////////////////////////////////////
/// \brief  Detects if a ray intersects a rectangle
///
/// This function is used in the Dynamic AABB collision detection
/// algorithm.
///
/// \param rayOrigin the origin of the ray
/// \param rayDirection the direction and distance of the ray
/// \param rect the rectangle to test the intersection on
///
/// \return the collision information of the intersection
///
/// \see DynamicRectangleCollision
///
////////////////////////////////////////////////////////////
CollisionInfo RayRectangleCollision(const sf::Vector2f& rayOrigin, const sf::Vector2f& rayDirection, const sf::FloatRect& rect);

////////////////////////////////////////////////////////////
/// \brief  Detects if moving rectangle collides with another rectangle
///
/// This function implements the Dynamic AABB collision detection.
/// For more information, see TODO(include link)
///
/// \param rect1 the moving rectangle
/// \param rect2 the static rectangle
/// \param collisionVector the movement vector of rect1
///
/// \return the collision information
///
////////////////////////////////////////////////////////////
CollisionInfo DynamicRectangleCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2, const sf::Vector2f& collisionVector);