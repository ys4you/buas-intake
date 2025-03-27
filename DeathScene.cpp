#include "precomp.h"
#include "DeathScene.h"
#include "GameLoopScene.h"
#include "FSMSceneController.h"

#include <iostream>


void DeathScene::onEnter(Surface* /* screen */)
{
	std::cout << "Entering death Scene\n";

}

void DeathScene::onUpdate(float deltaTime, Surface* screen)
{
	screen->Clear(0);

	screen->PrintScaled("You died...", SCRWIDTH / 3 + 44, SCRHEIGHT / 2, 4, 4, 0xffffff);
	screen->PrintScaled("Press enter to restart the game", SCRWIDTH / 3, SCRHEIGHT / 2 + 32, 2, 2, 0xffffff);
}

void DeathScene::onExit(Surface* /*screen */)
{
	std::cout << "Exiting death Scene\n";

}

void DeathScene::checkSwitchState()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!enterPressed)
		{
			FSMSceneController::Get()->changeState(std::move(std::make_unique<GameLoopScene>()));
			enterPressed = true;
		}
	}
	else
	{
		enterPressed = false;
	}
}
