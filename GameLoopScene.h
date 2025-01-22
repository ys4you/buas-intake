#include "SceneBaseState.h"
#include <iostream>

class GameLoopScene : public SceneBaseState {
public:
    void onEnter(FSMSceneController& controller, Surface* screen) override;

    void onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen) override;

    void onExit(FSMSceneController& controller, Surface* screen) override;

    void checkSwitchState(FSMSceneController& controller) override;
};