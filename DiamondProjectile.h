#pragma once
#include "GameObject.h"
#include "Projectile.h"

/// @brief Represents a diamond-shaped projectile fired in the game.
class DiamondProjectile : public Projectile {
public:
    /// @brief Constructor to initialize the DiamondProjectile object.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param speed The speed of the projectile (default is 0).
    /// @param pos The position of the projectile (default is {0, 0}).
    /// @param goingUp A flag indicating whether the projectile is moving upwards (default is true).
    /// @param objSize The size of the projectile (default is {32, 64}).
    /// @param filePath The file path for the texture (default is "assets/art/enemy/dummy/sharpDiamond.png").
    /// @param objName The name of the object (default is "DiamondProjectile").
    /// @param collider The collider type for the object (default is AABB).
    DiamondProjectile(
        Surface* screen,
        float speed = 0.f,
        const glm::vec2& pos = { 0,0 },
        bool goingUp = true,
        const glm::vec2& objSize = { 32, 64 },
        std::string filePath = "assets/art/enemy/dummy/sharpDiamond.png",
        const std::string& objName = "DiamondProjectile",
        Collider collider = Collider(ColliderType::AABB))
        : Projectile(
            screen,
            pos,
            objSize,
            goingUp ? -speed : speed, // Ternary operator 
            std::move(filePath),
            objName,
            collider), goingUp(goingUp)
    {
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

private:
    bool goingUp = true;

    /// @brief Updates the projectile's position and behavior.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;
};
