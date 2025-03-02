#include "precomp.h"
#include "game.h"

//SceneFSM
#include "FSMSceneController.h"
#include "MainMenuScene.h"
#include "GameLoopScene.h"

#include "GameObjectManager.h"

//vars
FSMSceneController sceneController;
//init scenes
std::unique_ptr<SceneBaseState> mainMenuScene = std::make_unique<MainMenuScene>();
std::unique_ptr<SceneBaseState> gameLoopScene = std::make_unique<GameLoopScene>();

void Game::Init()
{
    sceneController.initialize(screen);
    sceneController.changeState(std::move(gameLoopScene));
}
float DeltaTime;
void Game::Tick(float deltaTime)
{
    //screen->Clear(0);
	GameObjectManager::Get().UpdateAllObjects(DeltaTime);
    CheckStates();
    sceneController.update(DeltaTime);

}

void Game::CheckStates()
{
    DeltaTime /= 1000.0f; //convert to seconds
    if (sceneController.mainMenuButtonState == 2 && !sceneController.buttonsDisabled)
    {
        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            sceneController.changeState(std::move(gameLoopScene));
            gameLoopScene = std::make_unique<GameLoopScene>(); // Reset de variabele na switch
            sceneController.buttonsDisabled = true;
        }
    }
}
