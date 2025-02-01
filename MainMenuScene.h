#include "SceneBaseState.h"
#include "sprite.h"
#include "surface.h"
#include <iostream>

class MainMenuScene : public SceneBaseState {
private:
public:
    void onEnter(FSMSceneController& controller, Surface* screen) override;

    void onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen) override;

    void onExit(FSMSceneController& controller, Surface* screen) override;

    void checkSwitchState(FSMSceneController& controller) override;
};