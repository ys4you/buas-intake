#pragma once

class FSMSceneController; // Forward declaration this is so the other states can acces it

class SceneBaseState {
public:
    virtual ~SceneBaseState() = default;

    // Methods to be overridden by specific scenes
    virtual void onEnter(Surface* screen) = 0;
    virtual void onUpdate(float deltaTime, Surface* screen) = 0;
    virtual void onExit(Surface* screen) = 0;
    virtual void checkSwitchState() = 0;
};