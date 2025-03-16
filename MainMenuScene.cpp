#include "precomp.h"
#include "MainMenuScene.h"
#include <windows.h>
#include <cstdlib>

#include "FSMSceneController.h"
#include "GameLoopScene.h"

extern std::unique_ptr<SceneBaseState> gameLoopScene = std::make_unique<GameLoopScene>();

void MainMenuScene::onEnter(Surface* screen)
{
    std::cout << "Entering Main Menu Scene\n";

    controlsButton = new Button(
        screen,
        glm::vec2(50, 50),
        glm::vec2(0, 0),
        "assets/art/mainmenu/controls_inactive.png",
        "assets/art/mainmenu/controls_active.png",  
        "controlsButton"
    );

    playButton = new Button(
        screen,
        glm::vec2(50, 150),
        glm::vec2(0, 0),
        "assets/art/mainmenu/play_inactive.png",
        "assets/art/mainmenu/play_active.png",  
        "playButton"
    );

    quitButton = new Button(
        screen,
        glm::vec2(50, 250),
        glm::vec2(0, 0),
        "assets/art/mainmenu/quit_inactive.png",
        "assets/art/mainmenu/quit_active.png",  
        "quitButton"
    );

}



void MainMenuScene::onUpdate(float deltaTime, Surface* screen)
{
    screen->Clear(0);

    if (GetAsyncKeyState(VK_RETURN) & 0x8000)
    {
        if (!enterPressed)
        {
            enterPressed = true;
        }
    }
    else
        enterPressed = false;

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
    {
        if (!leftPressed) // Only trigger once per press
        {
            mainMenuButtonState--;
            leftPressed = true;
        }
    }
    else
        leftPressed = false;

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
    {
        if (!rightPressed) // Only trigger once per press
        {
            mainMenuButtonState++;
            rightPressed = true;
        }
    }
    else 
    {
        rightPressed = false;
    }

    if (mainMenuButtonState <= 0)
    {
        mainMenuButtonState = 3;
    }
    else if (mainMenuButtonState >= 4)
    {
        mainMenuButtonState = 1;
    }

    switch (mainMenuButtonState)
    {
    case 1: // start at 1
        controlsButton->IsActive(true);
        playButton->IsActive(false);
        quitButton->IsActive(false);
        break;

    case 2:
        controlsButton->IsActive(false);
        playButton->IsActive(true);
        quitButton->IsActive(false);
        break;

    case 3:
        controlsButton->IsActive(false);
        playButton->IsActive(false);
        quitButton->IsActive(true);
        if (leftPressed)
            exit(0);
        break;

    default:
        break;
    }

}

void MainMenuScene::onExit(Surface* screen)
{
    std::cout << "Exiting Main Menu Scene\n";

    // Delete the dynamically allocated Button objects
    controlsButton->MarkForDeletion();
    playButton->MarkForDeletion();
    quitButton->MarkForDeletion();

    // Set the pointers to nullptr to avoid dangling references
    controlsButton = nullptr;
    playButton = nullptr;
    quitButton = nullptr;
}


void MainMenuScene::checkSwitchState()
{
    if (mainMenuButtonState == 2 && enterPressed)
    {
        FSMSceneController::Get()->changeState(std::move(gameLoopScene));
        gameLoopScene = std::make_unique<GameLoopScene>(); // Reset de variabele na switch
    }

}