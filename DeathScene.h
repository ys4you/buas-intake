#include "SceneBaseState.h"
#include "surface.h"


class DeathScene : public SceneBaseState {

public:
    void onEnter(Surface* screen) override;

    void onUpdate(float deltaTime, Surface* screen) override;

    void onExit(Surface* screen) override;

    void checkSwitchState() override;
};
