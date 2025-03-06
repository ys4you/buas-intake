#include "precomp.h"
#include "MainMenuScene.h"
#include <windows.h>
#include <cstdlib>

#include "FSMSceneController.h"

#include "Button.h"



void MainMenuScene::onEnter(FSMSceneController& controller, Surface* screen)
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



void MainMenuScene::onUpdate(FSMSceneController& controller, float deltaTime, Surface* screen)
{
    screen->Clear(0);

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
    {
        if (!leftPressed) // Only trigger once per press
        {
            controller.mainMenuButtonState--;
            leftPressed = true;
        }
    }
    else
    {
        leftPressed = false;
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
    {
        if (!rightPressed) // Only trigger once per press
        {
            controller.mainMenuButtonState++;
            rightPressed = true;
        }
    }
    else 
    {
        rightPressed = false;
    }

    if (controller.mainMenuButtonState <= 0)
    {
        controller.mainMenuButtonState = 3;
    }
    else if (controller.mainMenuButtonState >= 4)
    {
        controller.mainMenuButtonState = 1;
    }

    if (!controller.buttonsDisabled)
    {
        switch (controller.mainMenuButtonState)
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
            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
                exit(0);
            break;

        default:
            break;
        }


    }
}

void MainMenuScene::onExit(FSMSceneController& controller, Surface* screen)
{
    std::cout << "Exiting Main Menu Scene\n";
    GameObjectManager::Get().RemoveGameObject(controlsButton->GetId());
    GameObjectManager::Get().RemoveGameObject(playButton->GetId());
    GameObjectManager::Get().RemoveGameObject(quitButton->GetId());
}

void MainMenuScene::checkSwitchState(FSMSceneController& controller)
{
}