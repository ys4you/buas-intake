#include "precomp.h"
#include "MainMenuScene.h"
#include <windows.h>
#include <cstdlib>

#include "FSMSceneController.h"
#include "GameLoopScene.h"
#include "AudioManager.h"


void MainMenuScene::onEnter(Surface* screen)
{
    std::cout << "Entering Main Menu Scene\n";

    int y = SCRHEIGHT / 3 * 2;
    int padding = 200;
    int x1 = 0 + padding;
    int x2 = SCRWIDTH - 128 - padding; 
    
    int spacing = (x2 - x1) / (3 - 1); // Calculate even spacing
    buttons.push_back(new Button(
        screen,
        glm::vec2(x1, y),
        glm::vec2(128, 64),
        "assets/art/mainmenu/controls_inactive.png",
        "assets/art/mainmenu/controls_active.png",
        "controlsButton"
    ));

    buttons.push_back(new Button(
        screen,
        glm::vec2(x1 + spacing, y),
        glm::vec2(128, 64),
        "assets/art/mainmenu/play_inactive.png",
        "assets/art/mainmenu/play_active.png",
        "playButton"
    ));

    buttons.push_back(new Button(
        screen,
        glm::vec2(x2, y),
        glm::vec2(128, 64),
        "assets/art/mainmenu/quit_inactive.png",
        "assets/art/mainmenu/quit_active.png",
        "quitButton"
    ));

    controls = new Sprite(new Surface("assets/art/controls.png"), 1);

}


void MainMenuScene::onUpdate(float deltaTime, Surface* screen)
{
    screen->Clear(0);

    if (isControlsActive)
    {
	    if (controls)
			controls->Draw(screen,0, 0);

        if (GetAsyncKeyState(VK_BACK) & 0x8000)
            isControlsActive = false;
	    return;
    }




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
        mainMenuButtonState = 1;
    }
    else if (mainMenuButtonState >= 4)
    {
        mainMenuButtonState = 3;
    }

    switch (mainMenuButtonState)
    {
    case 1: // start at 1
        buttons[0]->IsActive(true);
        buttons[1]->IsActive(false);
        buttons[2]->IsActive(false);
        if (enterPressed)
            isControlsActive = true;
        break;

    case 2:
        buttons[0]->IsActive(false);
        buttons[1]->IsActive(true);
        buttons[2]->IsActive(false);
        break;

    case 3:
        buttons[0]->IsActive(false);
        buttons[1]->IsActive(false);
        buttons[2]->IsActive(true);
        if (leftPressed)
            exit(0);
        break;

    default:
        break;
    }

    screen->PrintScaled("Enter is confirming/pressing the button and backspace is going 1 step back into a menu", 96, SCRHEIGHT - 32, 2, 2, 0xffffff);
    screen->PrintScaled("Menu's are moved with the arrow keys", SCRWIDTH / 3, SCRHEIGHT - 32 * 2, 2, 2, 0xffffff);
}

void MainMenuScene::onExit(Surface* screen)
{
    std::cout << "Exiting Main Menu Scene\n";

    for (auto button : buttons)
    {
        button->MarkForDeletion();
        button = nullptr;
    }
}


void MainMenuScene::checkSwitchState()
{
    if (mainMenuButtonState == 2 && enterPressed)
    {
        FSMSceneController::Get()->changeState(std::move(std::make_unique<GameLoopScene>()));
    }
}