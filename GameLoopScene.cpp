#include "precomp.h"
#include "GameLoopScene.h"
#include "FSMSceneController.h"


void GameLoopScene::onEnter(FSMSceneController& controller, Surface* screen)
{
	std::cout << "Entering Game Loop Scene\n";
}

void GameLoopScene::onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen)
{

}

void GameLoopScene::onExit(FSMSceneController& controller, Surface* screen)
{
	std::cout << "Exiting Game Loop Scene\n";
}

void GameLoopScene::checkSwitchState(FSMSceneController& controller)
{
	
}
