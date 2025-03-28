#include "precomp.h"
#include "game.h"

//SceneFSM
#include "AudioManager.h"
#include "DeathScene.h"
#include "FSMSceneController.h"
#include "MainMenuScene.h"

#include "GameObjectManager.h"

//vars
FSMSceneController* sceneController = FSMSceneController::Get();
//init scenes
std::unique_ptr<SceneBaseState> mainMenuScene = std::make_unique<MainMenuScene>();


void Game::Init()
{
    sceneController->initialize(screen);
    sceneController->changeState(std::move(mainMenuScene));
	//AudioManager::Get().initialize();


}

static int frame = 0;

void Game::Tick(float deltaTime)
{
	screen->Clear(0);

	//AudioManager::Get().playAudio("hit");

	sceneController->update(deltaTime);
	GameObjectManager::Get().UpdateAllObjects(deltaTime);

}
