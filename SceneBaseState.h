#pragma once

class SceneBaseState {
public:
    virtual ~SceneBaseState() = default;

    virtual void Enter() = 0;

    virtual void Update(float deltaTime) = 0;

    virtual void Exit() = 0;
};