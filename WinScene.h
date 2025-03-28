#include "SceneBaseState.h"
#include "surface.h"

/// @brief A derived class from SceneBaseState that manages the player's win scene.
class WinScene : public SceneBaseState {
public:
    /// @brief Tracks whether the Enter key has been pressed.
    bool enterPressed;

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

    /// @brief Checks whether a transition to another scene should occur.
    void checkSwitchState() override;
};
