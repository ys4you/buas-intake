#pragma once
#include "SceneBaseState.h"
#include "surface.h"
#include <iostream>
#include "Button.h"

/// @brief A scene that represents the main menu of the game.
class MainMenuScene : public SceneBaseState {
private:
    int mainMenuButtonState = 0;

    bool leftPressed = false;
    bool rightPressed = false;
    bool enterPressed = false;
    bool isControlsActive = false;

    std::vector<Button*> buttons;

    Sprite* controls = nullptr;

public:
    /// @brief Called when this scene is entered.
    /// @param screen A pointer to the Surface object for rendering.
    void onEnter(Surface* screen) override;

    /// @brief Updates the scene based on the elapsed time.
    /// @param deltaTime The time elapsed since the last frame update.
    /// @param screen A pointer to the Surface object for rendering.
    void onUpdate(float deltaTime, Surface* screen) override;

    /// @brief Called when this scene is exited.
    /// @param screen A pointer to the Surface object for rendering.
    void onExit(Surface* screen) override;

    /// @brief Checks if the scene should transition to another state.
    void checkSwitchState() override;
};
