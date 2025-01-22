#include "precomp.h"
#include "MainMenuScene.h"

#include "FSMSceneController.h"

void MainMenuScene::onEnter(FSMSceneController& controller, Surface* screen)
{
    std::cout << "Entering Main Menu Scene\n";
}

void MainMenuScene::onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen)
{
    screen->Clear(255);
    screen->Box(20, 20, 20, 20, 100);
}

void MainMenuScene::onExit(FSMSceneController& controller, Surface* screen)
{
    std::cout << "Exiting Main Menu Scene\n";
}

void MainMenuScene::checkSwitchState(FSMSceneController& controller)
{

}