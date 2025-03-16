#include "precomp.h"
#include "SphereProjectile.h"
#include "common.h"


void SphereProjectile::Test()
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

void SphereProjectile::Render()
{
    if (position.x - size.x <= SCRWIDTH && position.x + size.x >= 0 &&
        position.y + size.y <= SCRHEIGHT && position.y >= 0)
    {
	    if (shouldRender)
	    {
            //std::cout << "Rendering Object: " << name_ << " (" << Id << ")." << std::endl;

            if (file_.empty())
            {
                std::cout << "ERROR: Object: " << name_ << " (" << Id << ") Does not have a surface that can be rendered." << std::endl;
                return;
            }

            sprite_->DrawScaled(position.x, position.y, size.x, size.y, screen);
            //std::cout << size.x << ", " << size.y << std::endl;  
	    }
    }
}

void SphereProjectile::Update(float deltaTime)
{
    //check AABB
	if (collider.type == ColliderType::AABB)
    {
        collider.SetAABB(AABB(position, position + size));
#ifdef _DEBUG
        uint color = 0xFF0000; // Red color
        screen->Box(collider.aabb.min.x, collider.aabb.min.y,
            collider.aabb.max.x, collider.aabb.max.y, color);
#endif
    }

    //this checks if it needs to be rendered scaled or not, I have no clue why this works but this is the only option for it not to break.
	if (size.x == 32 && size.y == 32)
        GameObject::Render();
    else
        Render();

    Test();
}



