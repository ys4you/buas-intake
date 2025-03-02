#include "SceneBaseState.h"
#include <memory>


class FSMSceneController {
private:
    std::unique_ptr<SceneBaseState> currentState;
    Surface* screen;

public:
    FSMSceneController() : currentState(nullptr) {}

    void initialize(Surface* screen)
    {
        this->screen = screen;
    }
    // Change the current state
    void changeState(std::unique_ptr<SceneBaseState> newState);

    // Update the current state
    void update(float deltaTime);

    //Down below find vars that is accesable thru all states
    int pHealth;

    //MainMenu
    int mainMenuButtonState = 1;
    bool buttonsDisabled = false;
};
