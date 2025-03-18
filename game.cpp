#include "precomp.h"
#include "game.h"

//SceneFSM
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
	test = new Sprite(new Surface("assets/art/enemy/dummy/dummy-Sheet.png"), 8);

    sceneController->initialize(screen);
    sceneController->changeState(std::move(mainMenuScene));
}

static int frame = 0;

void Game::Tick(float deltaTime)
{
	screen->Clear(0);



	sceneController->update(deltaTime);
	GameObjectManager::Get().UpdateAllObjects(deltaTime);

	test->SetFrame(frame);
	test->Draw(screen, 100, 100);
	if (++frame == 8) frame = 0;

}
