#pragma once
#include "GameObject.h"
#include "common.h"

class SphereProjectile : public GameObject
{
public:
    SphereProjectile(
        Surface* screen,
        const glm::vec2& pos = { SCRWIDTH + 32 * 2, 0 },
        const glm::vec2& objSize = { 32, 32 },
        std::string filePath = "assets/art/enemy/dummy/bullet.png",
        const std::string& objName = "SphereProjectile",
        Collider collider = Collider(ColliderType::AABB))
        : GameObject(
            screen,
            pos,
            objSize,
            std::move(filePath),
            objName,
            collider) // Calling the base class constructor
    {
    }

    float bulletSpeed;

};

