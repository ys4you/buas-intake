#include "precomp.h"
#include "game.h"



//vars
SceneManager sceneManager;
std::unique_ptr<SceneBaseState> mainMenuState;

bool isInitialized;

void Game::Init()
{
	printf("init Main Menu scene state\n");
	mainMenuState = std::make_unique<MainMenu>();

	if (mainMenuState)
	{
		printf("sucesfully init Main Menu scene state\n");
		sceneManager.ChangeState(std::move(mainMenuState));
	}
}


void Game::Tick( float  deltaTime  )
{

    screen->Clear(0);

    // Update the current state
    sceneManager.Update(deltaTime);
}