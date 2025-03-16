#include "SceneBaseState.h"
#include "surface.h"
#include <iostream>

#include "Button.h"


class MainMenuScene : public SceneBaseState {
private:
    int mainMenuButtonState = 0;

    bool leftPressed = false;
    bool rightPressed = false;
    bool enterPressed = false;

    Button* controlsButton = nullptr;
    Button* playButton = nullptr;
    Button* quitButton = nullptr;


public:
    void onEnter(Surface* screen) override;

    void onUpdate(float deltaTime, Surface* screen) override;

    void onExit(Surface* screen) override;

    void checkSwitchState() override;
};
