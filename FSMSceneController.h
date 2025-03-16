#include "SceneBaseState.h"
#include <memory>

class FSMSceneController {
private:
    // Private constructor to prevent direct instantiation
    FSMSceneController() : currentState(nullptr), pHealth(100), mainMenuButtonState(1), buttonsDisabled(false) {}

    // Prevent copy construction and copy assignment
    FSMSceneController(const FSMSceneController&) = delete;
    FSMSceneController& operator=(const FSMSceneController&) = delete;

    std::unique_ptr<SceneBaseState> currentState;
    Surface* screen;

public:
    // Static method to get the single instance of the class
    static FSMSceneController* Get();

    // Optionally, you can also add a method to delete the instance, if needed
    static void destroyInstance();

    // Initialize with screen
    void initialize(Surface* screen);

    // Change the current state
    void changeState(std::unique_ptr<SceneBaseState> newState);

    // Update the current state
    void update(float deltaTime);

    // Accessible variables
    int pHealth;

    // MainMenu
    int mainMenuButtonState = 1;
    bool buttonsDisabled = false;

private:
    // Static instance pointer (declaration only)
    static FSMSceneController* instance;
};
