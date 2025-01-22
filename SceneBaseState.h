#pragma once

class FSMSceneController; // Forward declaration this is so the other states can acces it

class SceneBaseState {
public:
    virtual ~SceneBaseState() = default;

    // Methods to be overridden by specific scenes
    virtual void onEnter(FSMSceneController& controller, Surface* screen) = 0;
    virtual void onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen) = 0;
    virtual void onExit(FSMSceneController& controller, Surface* screen) = 0;
    virtual void checkSwitchState(FSMSceneController& controller) = 0;
};
