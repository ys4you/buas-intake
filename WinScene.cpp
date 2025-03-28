#include "precomp.h"
#include "WinScene.h"

#include <iostream>

#include "FSMSceneController.h"
#include "GameLoopScene.h"

void WinScene::onEnter(Surface* /* screen */)
{
	std::cout << "Entering death Scene\n";

}

void WinScene::onUpdate(float deltaTime, Surface* screen)
{
	screen->Clear(0);

	screen->PrintScaled("You won!!!!", SCRWIDTH / 3 + 44, SCRHEIGHT / 2, 4, 4, 0xffffff);
	screen->PrintScaled("Press enter to restart the game", SCRWIDTH / 3, SCRHEIGHT / 2 + 32, 2, 2, 0xffffff);
}

void WinScene::onExit(Surface* /*screen */)
{
	std::cout << "Exiting death Scene\n";

}

void WinScene::checkSwitchState()
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