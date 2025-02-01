#include "precomp.h"
#include "game.h"

//SceneFSM
#include "FSMSceneController.h"
#include "MainMenuScene.h"
#include "GameLoopScene.h"

//vars
FSMSceneController sceneController;
//init scenes
std::unique_ptr<SceneBaseState> mainMenuScene = std::make_unique<MainMenuScene>();
std::unique_ptr<GameLoopScene> gameLoopScene = std::make_unique<GameLoopScene>();

void Game::Init()
{
    sceneController.initialize(screen);
    sceneController.changeState(std::move(mainMenuScene));
}

void Game::Tick(float  deltaTime)
{
    sceneController.update(deltaTime);
    std::cout << SCRHEIGHT << std::endl;
}