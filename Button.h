#pragma once

#include "GameObject.h"

/// @brief Represents a UI button in the game.
class Button : public GameObject
{
public:
    /// @brief Constructs a Button object.
    /// @param screen The rendering surface.
    /// @param pos The position of the button.
    /// @param objSize The size of the button.
    /// @param buttonInactivePath The file path for the inactive button sprite.
    /// @param buttonActivePath The file path for the active button sprite.
    /// @param objName The name of the button.
    /// @param sRender Determines if the button should be rendered initially.
    Button(Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        const std::string& buttonInactivePath = "",
        const std::string& buttonActivePath = "",
        const std::string& objName = "Box",
        bool sRender = true)
        : GameObject(screen, pos, 1, objSize, buttonInactivePath, objName), // Calling base class
        buttonInactivePath(buttonInactivePath),
        buttonActivePath(buttonActivePath),
        shouldRender(sRender)

    {
        if (!buttonActivePath.empty())
            buttonActive = new Sprite(new Surface(buttonActivePath.c_str()), 1);

        if (!buttonInactivePath.empty())
            buttonInactive = new Sprite(new Surface(buttonInactivePath.c_str()), 1);
    }

    /// @brief Destructor for Button.
    ~Button() override;

    /// @brief Updates the button's state.
    /// @param deltaTime Time elapsed since the last update.
    void Update(float deltaTime) override;

    /// @brief Sets whether the button should be rendered.
    /// @param newRenderState True to render, false to hide.
    void SetRenderState(bool newRenderState) {shouldRender = newRenderState; }

    /// @brief Sets the active state of the button.
    /// @param isActive True if the button is active, false if inactive.
    void IsActive(bool isActive);
private:
    std::string buttonInactivePath;
    std::string buttonActivePath;
    bool shouldRender = true;
    Sprite* buttonActive;
    Sprite* buttonInactive;
    void RenderButton(Sprite* sprite);
};
