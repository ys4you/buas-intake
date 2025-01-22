#include "precomp.h"
#include "FSMSceneController.h"

// Change the current state
void FSMSceneController::changeState(std::unique_ptr<SceneBaseState> newState) {
    if (currentState) {
        currentState->onExit(*this, screen);
    }
    currentState = std::move(newState);
    if (currentState) {
        currentState->onEnter(*this, screen);
    }
}

// Update the current state

void FSMSceneController::update(float deltaTime) {
    if (currentState) {
        currentState->onUpdate(*this, deltaTime, screen);
    }
}
