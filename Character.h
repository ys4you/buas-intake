#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
    Character(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Character")
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName) // Calling the base class constructor
    {
    }

    int healthPoints;
    int maxHealthPoints;

    int damage;

    void Heal(int amount);

    void TakeDamage(int amount);

    void Die();

    //Buttons
	void Fight();
    virtual void PerformUniqueAction();
    void Item();
    void Spare();
    void Defend();

};

