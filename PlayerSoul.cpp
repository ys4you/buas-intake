#include "precomp.h"
#include "PlayerSoul.h"

#include <Windows.h>  // For GetAsyncKeyState

void PlayerSoul::Update(float deltaTime)
{
    GameObject::Update(deltaTime);

    float speed = 20.f * (deltaTime / 1000.f);
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

    // Apply movement
    position.x += moveX * speed * deltaTime;
    position.y += moveY * speed * deltaTime;


    GameObject::SetPosition(position);
}