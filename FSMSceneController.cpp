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
    this->screen = screen;
}

void FSMSceneController::changeState(std::unique_ptr<SceneBaseState> newState)
{
    if (currentState)
    {
        currentState->onExit(screen);
    }
    currentState = std::move(newState);
    if (currentState)
    {
        currentState->onEnter(screen);
    }
}

void FSMSceneController::update(float deltaTime)
{
    if (currentState) {
        currentState->onUpdate(deltaTime, screen);
        currentState->checkSwitchState();
    }
}
