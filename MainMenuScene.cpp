#include "precomp.h"
#include "MainMenuScene.h"

#include "FSMSceneController.h"

static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
int frame = 0;

void MainMenuScene::onEnter(FSMSceneController& controller, Surface* screen)
{
    std::cout << "Entering Main Menu Scene\n";
}

void MainMenuScene::onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen)
{
    screen->Clear(0);
    rotatingGun.SetFrame(frame);
    rotatingGun.Draw(screen, 0, 0);
    if (++frame == 36) frame = 0;
}

void MainMenuScene::onExit(FSMSceneController& controller, Surface* screen)
{
    std::cout << "Exiting Main Menu Scene\n";
}

void MainMenuScene::checkSwitchState(FSMSceneController& controller)
{

}