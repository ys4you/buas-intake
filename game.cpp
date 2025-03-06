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
    sceneController.changeState(std::move(mainMenuScene));
}
void Game::Tick(float deltaTime)
{
    //screen->Clear(0);
    CheckStates();
    sceneController.update(deltaTime);

	GameObjectManager::Get().UpdateAllObjects(deltaTime);

}

void Game::CheckStates()
{
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
