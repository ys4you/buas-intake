#pragma once
#include <utility>

#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Player")
        : GameObject(
            screen,
            pos,
            objSize,
            std::move(filePath),
            objName) // Calling the base class constructor
    {
    }

    void Update(float deltaTime) override;

};
