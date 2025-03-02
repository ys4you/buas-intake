#include "SceneBaseState.h"
#include "surface.h"
#include <iostream>

#include "Button.h"

class MainMenuScene : public SceneBaseState {
private:
    bool leftPressed = false;
    bool rightPressed = false;

    Button* controlsButton = nullptr;
    Button* playButton = nullptr;
    Button* quitButton = nullptr;

public:
    void onEnter(FSMSceneController& controller, Surface* screen) override;

    void onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen) override;

    void onExit(FSMSceneController& controller, Surface* screen) override;

    void checkSwitchState(FSMSceneController& controller) override;
};
