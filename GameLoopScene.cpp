#include "precomp.h"
#include "GameLoopScene.h"
#include "FSMSceneController.h"
#include "Player.h"

void GameLoopScene::onEnter(FSMSceneController& controller, Surface* screen)
{
	std::cout << "Entering Game Loop Scene\n";

	player = new Player(
		screen,
		glm::vec2(50, 50),
		glm::vec2(28, 28),
		"assets/art/player.png",
		"Hero");
}
//Sprite controlsActive(new Surface("assets/art/player.png"), 1);

void GameLoopScene::onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen)
{
	screen->Clear(0);
	//works
	std::cout << "updating now: " << player->GetName() << "with pointer: " << player << std::endl;
	//player->Update(deltaTime);
}

void GameLoopScene::onExit(FSMSceneController& controller, Surface* screen)
{
	std::cout << "Exiting Game Loop Scene\n";
}

void GameLoopScene::checkSwitchState(FSMSceneController& controller)
{
	
}