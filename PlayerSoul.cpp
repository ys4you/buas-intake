#include "precomp.h"
#include "PlayerSoul.h"

#include <Windows.h>  // For GetAsyncKeyState

#include "FSMSceneController.h"

#include "DeathScene.h"

void PlayerSoul::Update(float deltaTime)
{
    GameObject::Update(deltaTime);

    float speed = 0.3f;
    float moveX = 0.f;
    float moveY = 0.f;

    // WASD movement logic using GetAsyncKeyState
    if (GetAsyncKeyState('W') & 0x8000) // Move up
    {
        moveY -= 1.f;
    }
    if (GetAsyncKeyState('S') & 0x8000) // Move down
    {
        moveY += 1.f;
    }
    if (GetAsyncKeyState('A') & 0x8000) // Move left
    {
        moveX -= 1.f;
    }
    if (GetAsyncKeyState('D') & 0x8000) // Move right
    {
        moveX += 1.f;
    }

    // Normalize if moving diagonally. If you do not do this. The velocity of diagonal movement wil be slightly faster than horizontal and vertical
    float magnitude = sqrt(moveX * moveX + moveY * moveY);
    if (magnitude > 0.f)
    {
        moveX /= magnitude;
        moveY /= magnitude;
    }

    position.x += moveX * speed * deltaTime;
    position.y += moveY * speed * deltaTime;

    int j = 0;
    SetPosition(position);
    //std::cout << "Player pos: x: " << position.x << " y: " << position.y << std::endl;
    screen->PrintScaled("HP:", positionOfUI.x - 50.f, positionOfUI.y + 10.f, 2, 2, 0xFFFFFF);
    for (int i = 0; i < maxHealthPoints; ++i)
    {
	    if (i <= healthPoints)
	    {
			screen->Line(positionOfUI.x + i, positionOfUI.y, positionOfUI.x + i, positionOfUI.y + 25, 0xFF0000);
	    }
        else
        {
            screen->Line(positionOfUI.x + i, positionOfUI.y, positionOfUI.x + i, positionOfUI.y + 25, 0x222222);
        }
    }
    std::string hpUI = std::to_string(healthPoints) + "/" + std::to_string(maxHealthPoints);
    screen->PrintScaled(hpUI.c_str(), positionOfUI.x + maxHealthPoints + 10.f, positionOfUI.y + 10.f, 2, 2, 0xFFFFFF);

}

// Function to handle taking damage
void PlayerSoul::TakeDamage(int damageAmount) {

    healthPoints -= damageAmount;
    std::cout << "player took damage heath is now: "  << healthPoints << std::endl;
    if (healthPoints <= 0) {
        healthPoints = 0;
        Die(); 
    }
}

void PlayerSoul::Die() {
    hasDied = true;
    std::cout << "player has died!" << std::endl;

}

void PlayerSoul::Heal(int healAmount) {
    healthPoints += healAmount;
    if (healthPoints > maxHealthPoints) {
        healthPoints = maxHealthPoints; 
    }
}