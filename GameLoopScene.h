#include "SceneBaseState.h"
#include <iostream>

//GameObjects
#include "PlayerSoul.h"
#include "Box.h"
#include "ActionMenu.h"

//attacks
#include "DummyAtackOne.h"

class GameLoopScene : public SceneBaseState {
public:
    void onEnter(FSMSceneController& controller, Surface* screen) override;

    void onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen) override;

    void onExit(FSMSceneController& controller, Surface* screen) override;

    void checkSwitchState(FSMSceneController& controller) override;

    PlayerSoul* player = nullptr;
    Box* box = nullptr;
    ActionMenu* actionMenu = nullptr;
    DummyAtackOne* attack = nullptr;
};
