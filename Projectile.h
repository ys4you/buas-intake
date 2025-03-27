#pragma once
#include "GameObject.h"
#include "PlayerSoul.h"

/// @brief Represents a basic projectile fired in the game.
class Projectile : public GameObject {
public:
    /// @brief Constructor to initialize the Projectile object.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param pos The position of the projectile (default is {0, 0}).
    /// @param objSize The size of the projectile (default is {32, 32}).
    /// @param speed The speed of the projectile (default is 0).
    /// @param filePath The file path for the texture (default is an empty string).
    /// @param objName The name of the object (default is "Projectile").
    /// @param collider The collider type for the object (default is AABB).
    Projectile(
        Surface* screen,
        const glm::vec2& pos = { 0,0 },
        const glm::vec2& objSize = { 32, 32 },
        float speed = 0,
        std::string filePath = "",
        const std::string& objName = "Projectile",
        Collider collider = Collider(ColliderType::AABB))
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName,
            collider), speed(speed)
    {
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

protected:
    float speed = 0;
    GameObject* playerObj = nullptr;
    PlayerSoul* player = nullptr;
    bool shouldRender = true;

    /// @brief Checks for collisions of the projectile with the player.
    void CollisionCheck()
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

    /// @brief Updates the projectile's position, checks boundaries, and handles collisions.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float /*deltaTime */) override
    {
        if (collider.type == ColliderType::AABB)
        {
            collider.SetAABB(AABB(position, position + size));
#ifdef _DEBUG
            uint color = 0xFF0000; // Red color
            screen->Box(collider.aabb.min.x, collider.aabb.min.y,
                collider.aabb.max.x, collider.aabb.max.y, color);
#endif
        }

        if (position.x - size.x <= SCRWIDTH && position.x + size.x >= 0 &&
            position.y + size.y <= SCRHEIGHT && position.y >= 0 - size.y)
            shouldRender = true;
        else
            shouldRender = false;

        Render();

        CollisionCheck();
    }

    /// @brief Renders the projectile on the screen.
    void Render() override
    {
        if (position.x - size.x <= SCRWIDTH && position.x + size.x >= 0 &&
            position.y + size.y <= SCRHEIGHT && position.y >= 0 - size.y)
        {
            if (file_.empty())
            {
                std::cout << "ERROR: Object: " << name_ << " (" << Id << ") Does not have a surface that can be rendered." << std::endl;
                return;
            }

            sprite_->Draw(screen, position.x, position.y);
        }
    }
};
