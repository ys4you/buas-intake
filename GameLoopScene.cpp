#include "precomp.h"
#include "GameLoopScene.h"

#include "FSMSceneController.h"
#include "PlayerSoul.h"
#include "common.h"
#include "DeathScene.h"

void GameLoopScene::onEnter(Surface* screen)
{
	std::cout << "Entering Game Loop Scene\n";

#pragma region GameObjects initializing
	player = new PlayerSoul(
		screen,
		glm::vec2(700, 300),
		glm::vec2(28, 28),
		"assets/art/player.png",
		"PlayerSoul",
		100,
		100);


	box = new Box(
		screen,
		glm::vec2((SCRWIDTH/2)-125, SCRHEIGHT / 3 -125),
		glm::vec2(250, 250),
		"Box"
		);

	dummy = new DummyEnemy(screen, box, { SCRWIDTH / 4 * 3, SCRHEIGHT/ 2} );
	int centerValue = 200;
	actionMenu = new ActionMenu(
		screen,
		glm::vec2(centerValue, SCRHEIGHT- 200 - 1),
		glm::vec2(SCRWIDTH - (centerValue*2), 200-1),
		"ActionMenu"
	);
#pragma endregion

}

void GameLoopScene::onUpdate(float deltaTime, Surface* screen)
{
	screen->Clear(0);
	player->KeepInsideBoundary(box->GetCollider());

}

void GameLoopScene::onExit(Surface* screen)
{
	std::cout << "Exiting Game Loop Scene\n";

	if(isDeleted_)
		return;

	box->MarkForDeletion();
	actionMenu->MarkForDeletion();
	player->MarkForDeletion();

	box = nullptr;
	actionMenu = nullptr;
	player = nullptr;

	isDeleted_ = true;
}

void GameLoopScene::checkSwitchState()
{
	if (player->hasDied)
	{
		std::unique_ptr<DeathScene> deathScene = std::make_unique<DeathScene>();
		FSMSceneController::Get()->changeState(std::move(deathScene));
	}
}