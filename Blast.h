#pragma once
#include "GameObject.h"
#include "PlayerSoul.h"

/// @brief Represents a Blast object in the game, typically an enemy or projectile.
class Blast : public GameObject {
public:
    /// @brief Constructor to initialize the Blast object.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param pos The position of the object (default is {0, 0}).
    /// @param objSize The size of the object (default is {0, 0}).
    /// @param randomDir A random direction value for the blast (default is -1).
    /// @param filePath The file path for the texture (default is "assets/art/enemy/dummy/pixel.png").
    /// @param objName The name of the object (default is "Blast").
    /// @param collider The collider type for the object (default is AABB).
    Blast(
        Surface* screen,
        const glm::vec2& pos = { 0,0 },
        const glm::vec2& objSize = { 0, 0 },
        int randomDir = -1,
        std::string filePath = "assets/art/enemy/dummy/pixel.png",
        const std::string& objName = "Blast",
        Collider collider = Collider(ColliderType::AABB))
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName,
            collider), randomDir(randomDir)
    {
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

private:
    GameObject* playerObj = nullptr;
    PlayerSoul* player = nullptr;
    int randomDir = -1;

    /// @brief Checks for collisions with other objects.
    void CollisionCheck();

    /// @brief Renders the Blast object on the screen.
    void Render() override;

    /// @brief Updates the Blast object.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;
};
