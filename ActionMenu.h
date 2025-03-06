#pragma once
#include "GameObject.h"

class ActionMenu : public GameObject
{
public:
    ActionMenu(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        const std::string& objName = "ActionMenu")
        : GameObject(
            screen,
            pos,
            objSize,
            "",
            objName) // Calling the base class constructor
    {
    }

    void Render() override;
};

