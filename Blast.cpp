#include "precomp.h"
#include "Blast.h"

void Blast::CollisionCheck()
{
    if (playerObj == nullptr)
        return;

    if (CheckCollision(*playerObj))
    {
        if (!player)
        {
            player = dynamic_cast<PlayerSoul*>(playerObj);

            if (player == nullptr)
                return;
        }

        if (player != nullptr)
        {
            player->TakeDamage(1);
        }
    }
}

void Blast::Render()
{

    screen->Box(
        position.x, position.y,
        position.x + size.x, position.y + size.y,
        0xFFFFFF
    );
}

void Blast::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
    CollisionCheck();
}
