#include "SceneBaseState.h"
#include <iostream>

//GameObjects
#include "PlayerSoul.h"
#include "Box.h"
#include "ActionMenu.h"

//attacks
#include "CircleAttack.h"
#include "DummyAttackOne.h"

class GameLoopScene : public SceneBaseState {
public:
    void onEnter(Surface* screen) override;

    void onUpdate(float deltaTime, Surface* screen) override;

    void onExit(Surface* screen) override;

    void checkSwitchState() override;

    PlayerSoul* player = nullptr;
    Box* box = nullptr;
    ActionMenu* actionMenu = nullptr;
    DummyAttackOne* attack = nullptr;
    CircleAttack* cAttack = nullptr;
    SphereProjectile* projectile = nullptr;
    bool isDeleted_ = false;
};
