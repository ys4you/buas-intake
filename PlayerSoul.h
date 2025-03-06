#pragma once
#include <utility>

#include "GameObject.h"

class PlayerSoul : public GameObject
{
public:
    PlayerSoul(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Player",
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

    int healthPoints;
    int maxHealthPoints;

    void Update(float deltaTime) override;

};
