#pragma once

#include "GameObject.h"

class Button : public GameObject
{
public:
    Button(Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        const std::string& buttonInactivePath = "",
        const std::string& buttonActivePath = "",
        const std::string& objName = "Player")
        : GameObject(screen, pos, objSize, buttonInactivePath, objName), // Calling base class
        buttonInactivePath(buttonInactivePath),
        buttonActivePath(buttonActivePath)
    {
    }


    void Update(float deltaTime) override;

    void IsActive(bool isActive);
private:
    std::string buttonInactivePath;
    std::string buttonActivePath;

    void RenderButton(std::string file);
};
