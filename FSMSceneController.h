#include "SceneBaseState.h"
#include <memory>

/// @brief Manages scene states in a finite state machine (FSM) architecture.
class FSMSceneController {
private:
    /// @brief Private constructor to enforce the singleton pattern.
    FSMSceneController() : currentState(nullptr), screen_(nullptr) {}

    /// @brief Deleted copy constructor to prevent copying.
    FSMSceneController(const FSMSceneController&) = delete;

    /// @brief Deleted copy assignment operator to prevent copying.
    FSMSceneController& operator=(const FSMSceneController&) = delete;

    std::unique_ptr<SceneBaseState> currentState;
    Surface* screen_ = nullptr;

public:
    /// @brief Retrieves the singleton instance of the FSMSceneController.
    /// @return Pointer to the FSMSceneController instance.
	static FSMSceneController* Get();

    /// @brief Deletes the singleton instance if necessary.
    static void destroyInstance();

    /// @brief Initializes the scene controller with a screen surface.
    /// @param screen The surface used for rendering.
	void initialize(Surface* screen);

    /// @brief Changes the current scene state.
    /// @param newState The new scene state to switch to.
	void changeState(std::unique_ptr<SceneBaseState> newState);

    /// @brief Updates the current scene state.
    /// @param deltaTime The time elapsed since the last update.
	void update(float deltaTime);

private:
    // Static instance pointer (declaration only)
    static FSMSceneController* instance;
};
