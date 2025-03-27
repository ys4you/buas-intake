#include "SceneBaseState.h"
#include <iostream>

// GameObjects
#include "PlayerSoul.h"
#include "Box.h"
#include "ActionMenu.h"
#include "DummyEnemy.h"
#include "Turn.h"

/// @brief A scene that represents the main game loop, handling player and enemy interactions.
class GameLoopScene : public SceneBaseState {
public:
    PlayerSoul* player = nullptr;
    Box* box = nullptr;
    ActionMenu* actionMenu = nullptr;
    DummyEnemy* dummy = nullptr;

    bool isDeleted_ = false;
    Turn turn = Turn::Player;

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

private:
    /// @brief Retrieves the name of the current turn state as a string.
    /// @param currentTurn The current turn (player or enemy).
    /// @return A string representation of the current turn.
    std::string GetTurnName(Turn currentTurn);
};
