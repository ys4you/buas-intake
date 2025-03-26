#pragma once

#include <glm/vec2.hpp>
#include <glm/glm.hpp>

/// @brief Enum representing different types of colliders.
enum class ColliderType { AABB, Circle, None };

/// @brief Axis-Aligned Bounding Box (AABB) structure.
struct AABB
{
    /// @brief Default constructor initializing an empty AABB.
    AABB() : min(0.0f), max(0.0f) {}

    /// @brief Constructor initializing an AABB with given min and max points.
	/// @param min The minimum (bottom-left) point.
	/// @param max The maximum (top-right) point.
    AABB(glm::vec2 min, glm::vec2 max) : min(min), max(max) {}

    glm::vec2 min;
    glm::vec2 max;

};

/// @brief Collider component for collision detection.
struct Collider
{
    ColliderType type;
    AABB aabb;

    /// @brief Default constructor initializing a collider with no type.
    Collider() : type(ColliderType::None), aabb(){}

    /// @brief Constructor initializing a collider with a specific type.
	/// @param type The type of collider.
	explicit Collider(ColliderType type) : type(type), aabb() {}

    /// @brief Sets the AABB values if the collider type is AABB.
	/// @param newAABB The new AABB values to be set.
    void SetAABB(const AABB& newAABB)
    {
        if (type == ColliderType::AABB)
            aabb = newAABB;
    }

    /// @brief Checks collision between this collider and another.
	/// @param other The other collider to check collision against.
	/// @return Returns true if there is a collision; otherwise, false.
    bool CheckCollision(const Collider& other) const
    {

            if (this->type == ColliderType::AABB)
            {
                return CheckAABBCollision(this->aabb, other.aabb);
            }

        return false;
    }


private:
    /// @brief Checks if two AABBs are colliding.
	/// @param a First AABB.
	/// @param b Second AABB.
	/// @return Returns true if the two AABBs overlap.
    static bool CheckAABBCollision(const AABB& a, const AABB& b)
    {
        return (a.min.x < b.max.x &&
            a.max.x > b.min.x &&
            a.min.y < b.max.y &&
            a.max.y > b.min.y);
    }

};
