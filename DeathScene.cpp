#include "precomp.h"
#include "DeathScene.h"

#include <iostream>


void DeathScene::onEnter(Surface* screen)
{
	std::cout << "Entering death Scene\n";

}

void DeathScene::onUpdate(float deltaTime, Surface* screen)
{
	screen->Clear(0);
}

void DeathScene::onExit(Surface* screen)
{
	std::cout << "Exiting death Scene\n";

}

void DeathScene::checkSwitchState()
{
}