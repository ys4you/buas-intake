#include "SceneBaseState.h"
#include <iostream>

//GameObjects
#include "PlayerSoul.h"
#include "Box.h"
#include "ActionMenu.h"
#include "DummyEnemy.h"
#include "Turn.h"


class GameLoopScene : public SceneBaseState {
public:
    void onEnter(Surface* screen) override;

    void onUpdate(float deltaTime, Surface* screen) override;

    void onExit(Surface* screen) override;

    void checkSwitchState() override;

    PlayerSoul* player = nullptr;
    Box* box = nullptr;
    ActionMenu* actionMenu = nullptr;
    DummyEnemy* dummy = nullptr;


    bool isDeleted_ = false;
    Turn turn = Turn::Player;
private:
    std::string GetTurnName(Turn currentTurn);
};
