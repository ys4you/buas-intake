#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(
        Surface* screen,
        int maxHealthPoints,
        int healthPoints,
        int frames = 1,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Character")
        : GameObject(
            screen,
            pos,
            frames,
            objSize,
            std::move(filePath),
            objName), // Calling the base class constructor
        maxHealthPoints(maxHealthPoints), healthPoints(healthPoints), damage(0)
    {
    }

    int maxHealthPoints = 0;
    int healthPoints = 0;

    int damage = 0;

    void Update(float deltaTime) override;

    void TakeDamage(int amount);

    void Die();
};
