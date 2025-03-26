#pragma once

class FSMSceneController; // Forward declaration so other states can access it

/// @brief Abstract base class for scene states in a finite state machine.
class SceneBaseState {
public:
    virtual ~SceneBaseState() = default;

    /// @brief Called when entering this scene state.
    /// @param screen The surface where the scene will be drawn.
    virtual void onEnter(Surface* screen) = 0;

    /// @brief Updates the scene state logic.
    /// @param deltaTime The time elapsed since the last update.
    /// @param screen The surface where the scene is drawn.
    virtual void onUpdate(float deltaTime, Surface* screen) = 0;

    /// @brief Called when exiting this scene state.
    /// @param screen The surface where the scene was drawn.
    virtual void onExit(Surface* screen) = 0;

    /// @brief Checks and handles transitions between scene states.
    virtual void checkSwitchState() = 0;
};
