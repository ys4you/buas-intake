#pragma once
#include "GameObject.h"

class Enemy : public GameObject 
{
public:
    Enemy(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Character")
        : GameObject(
            screen,
            pos,
            objSize,
            std::move(filePath),
            objName) // Calling the base class constructor
    {
    }

    int healthPoints;
    int maxHealthPoints;

    int damage;

    void TakeDamage(int amount);

    void Die();

};  