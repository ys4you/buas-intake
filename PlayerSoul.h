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
        const std::string& objName = "PlayerSoul",
        int maxHealth = 100,        // Default max health
        int health = 100,           // Default current health
        Collider collider = Collider(ColliderType::AABB)

    )
        : GameObject(
            screen,
            pos,
            objSize,
            std::move(filePath),
            objName,
            collider),
          healthPoints(health),
          maxHealthPoints(maxHealth)
    {
    }

    void TakeDamage(int damageAmount);
    void Die();
    void Heal(int healAmount);

    bool hasDied = false;

    int healthPoints;
    int maxHealthPoints;

private:

    void Update(float deltaTime) override;
};