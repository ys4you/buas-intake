#include "precomp.h"
#include "SceneManager.h"

#include <iostream>

void SceneManager::ChangeState(std::unique_ptr<SceneBaseState> newState)
{

    if (currentState) 
    {
        printf("Exiting current state...\n");
        currentState->Exit();
    }

    if (newState)
        currentState = std::move(newState); //Not working as expexted here
    else
        printf("newState is empty");

    if (currentState) 
    {
        printf("Entering new state...\n");
        currentState->Enter(); 
    }
    else {
        printf("No new state provided!\n");
    }
}


void SceneManager::Update(float deltaTime)
{
    if (currentState)
        currentState->Update(deltaTime);
    else
        printf("currentState is empty\n");
}
