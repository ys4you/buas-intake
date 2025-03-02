#pragma once

#include <glm/vec2.hpp>
#include <glm/glm.hpp>

enum class ColliderType { AABB, Circle };

struct AABB {
    glm::vec2 min;
    glm::vec2 max;

    AABB() : min(0.0f), max(0.0f) {}
    AABB(glm::vec2 min, glm::vec2 max) : min(min), max(max) {}
};

struct CircleCollider {
    glm::vec2 center;
    float radius;

    CircleCollider() : center(0.0f), radius(0.0f) {}
    CircleCollider(glm::vec2 center, float radius) : center(center), radius(radius) {}
};

struct Collider {
    ColliderType type;
    AABB aabb;
    CircleCollider circle;

    Collider() : type(ColliderType::AABB), aabb(), circle() {}
    Collider(AABB aabb) : type(ColliderType::AABB), aabb(aabb) {}
    Collider(CircleCollider circle) : type(ColliderType::Circle), circle(circle) {}

    bool CheckCollision(const Collider& other) const {
        if (this->type == other.type) {
            if (this->type == ColliderType::AABB) {
                return CheckAABBCollision(this->aabb, other.aabb);
            }
            else if (this->type == ColliderType::Circle) {
                return CheckCircleCollision(this->circle, other.circle);
            }
        }
        if ((this->type == ColliderType::AABB && other.type == ColliderType::Circle) ||
            (this->type == ColliderType::Circle && other.type == ColliderType::AABB)) {
            if (this->type == ColliderType::AABB) {
                return CheckAABBCollisionWithCircle(this->aabb, other.circle);
            }
            else {
                return CheckAABBCollisionWithCircle(other.aabb, this->circle);
            }
        }
        return false;
    }

private:
    static bool CheckAABBCollision(const AABB& a, const AABB& b) {
        return (a.min.x < b.max.x &&
            a.max.x > b.min.x &&
            a.min.y < b.max.y &&
            a.max.y > b.min.y);
    }

    static bool CheckCircleCollision(const CircleCollider& a, const CircleCollider& b) {
        float distance = glm::distance(a.center, b.center);
        float radiiSum = a.radius + b.radius;
        return distance <= radiiSum;
    }

    static bool CheckAABBCollisionWithCircle(const AABB& aabb, const CircleCollider& circle) {
        float closestX = glm::clamp(circle.center.x, aabb.min.x, aabb.max.x);
        float closestY = glm::clamp(circle.center.y, aabb.min.y, aabb.max.y);
        glm::vec2 closestPoint(closestX, closestY);
        float distance = glm::distance(circle.center, closestPoint);
        return distance <= circle.radius;
    }
};
