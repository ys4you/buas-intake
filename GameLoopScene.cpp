#include "precomp.h"
#include "GameLoopScene.h"
#include "FSMSceneController.h"
#include "PlayerSoul.h"
#include "common.h"

void GameLoopScene::onEnter(FSMSceneController& controller, Surface* screen)
{
	std::cout << "Entering Game Loop Scene\n";

	player = new PlayerSoul(
		screen,
		glm::vec2(700, 300),
		glm::vec2(28, 28),
		"assets/art/player.png",
		"Hero");

	box = new Box(
		screen,
		glm::vec2((SCRWIDTH/2)-125, SCRHEIGHT / 3 -125),
		glm::vec2(250, 250),
		"Box"
		);
	int centerValue = 200;
	actionMenu = new ActionMenu(
		screen,
		glm::vec2(centerValue, SCRHEIGHT- 200 - 1), // Centered horizontally, positioned 250 from the bottom
		glm::vec2(SCRWIDTH - (centerValue*2), 200-1),
		"ActionMenu"
	);

	attack = new DummyAtackOne(screen, 15);

	attack->DoingAttack();
}

void GameLoopScene::onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen)
{
	screen->Clear(0);
	player->KeepInsideBoundary(box->GetCollider());

	attack->Update(deltaTime);
}

void GameLoopScene::onExit(FSMSceneController& controller, Surface* screen)
{
	std::cout << "Exiting Game Loop Scene\n";
}

void GameLoopScene::checkSwitchState(FSMSceneController& controller)
{
	
}