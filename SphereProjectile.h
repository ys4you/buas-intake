#pragma once
#include "GameObject.h"
#include "common.h"
#include "PlayerSoul.h"

/// @brief Represents a sphere-shaped projectile fired in the game.
class SphereProjectile : public GameObject {
public:
    /// @brief Constructor to initialize the SphereProjectile object.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param pos The position of the projectile (default is {0, 0}).
    /// @param objSize The size of the projectile (default is {32, 32}).
    /// @param angle The angle of the projectile's movement (default is 0).
    /// @param filePath The file path for the texture (default is "assets/art/enemy/dummy/bullet.png").
    /// @param objName The name of the object (default is "SphereProjectile").
    /// @param collider The collider type for the object (default is AABB).
    SphereProjectile(
        Surface* screen,
        const glm::vec2& pos = { 0,0 },
        const glm::vec2& objSize = { 32, 32 },
        float angle = 0,
        std::string filePath = "assets/art/enemy/dummy/bullet.png",
        const std::string& objName = "SphereProjectile",
        Collider collider = Collider(ColliderType::AABB))
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName,
            collider), angle(angle)
    {
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

    float angle = 0;
    float speed = 500.f;
    float timer = 0.f;
    bool shouldRender = true;
    glm::vec2 initialDirection = glm::vec2(0.f, 0.f);

    GameObject* playerObj = nullptr;
    PlayerSoul* player = nullptr;

    /// @brief Checks for collisions of the projectile with other objects.
    void CollisionCheck();

    /// @brief Updates the projectile's position and behavior.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;

    /// @brief Renders the projectile on the screen.
    void Render() override;
};
