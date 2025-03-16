#pragma once
#include "BaseAttack.h"
#include "Enemy.h"
#include "GameObject.h"

class DummyEnemy : public Enemy
{
public:
    DummyEnemy(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Dummy")
        : Enemy(
            screen,
            pos,
            objSize,
            std::move(filePath),
            objName) // Calling the base class constructor
    {
    }
protected:
    std::vector<BaseAttack> attacks;
};

