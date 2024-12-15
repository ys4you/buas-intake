#pragma once

#include "SceneBaseState.h"
class MainMenu : public SceneBaseState {
public:
    void Enter() override;
    void Update(float deltaTime) override;
    void Exit() override;
};

