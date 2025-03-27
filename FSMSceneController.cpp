#include "precomp.h"
#include "FSMSceneController.h"

// Initialize static instance to nullptr
FSMSceneController* FSMSceneController::instance = nullptr;

FSMSceneController* FSMSceneController::Get()
{
    if (instance == nullptr) {
        instance = new FSMSceneController();
    }
    return instance;
}

void FSMSceneController::destroyInstance()
{
    delete instance;
    instance = nullptr;
}

void FSMSceneController::initialize(Surface* screen)
{
    this->screen_ = screen;
}

void FSMSceneController::changeState(std::unique_ptr<SceneBaseState> newState)
{
    if (currentState)
    {
        currentState->onExit(screen_);
    }
    currentState = std::move(newState);
    if (currentState)
    {
        currentState->onEnter(screen_);
    }
}

void FSMSceneController::update(float deltaTime)
{
    if (currentState) {
        currentState->onUpdate(deltaTime, screen_);
        currentState->checkSwitchState();
    }
}
