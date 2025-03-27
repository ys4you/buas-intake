#pragma once
#include "SphereProjectile.h"

/// @brief Represents a circle of projectiles in the game.
class Circle {
public:
    /// @brief Constructor to initialize the Circle object.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param amountOfProjectiles The number of projectiles in the circle.
    Circle(Surface* screen, int amountOfProjectiles)
        : screen(screen), projectilesAmount(amountOfProjectiles) {}

    ~Circle();

    Surface* screen;
    std::vector<SphereProjectile*> projectiles;
    glm::vec2 projSize = { 64, 64 };
    glm::vec2 center = { 640 - projSize.x / 2, 240 - projSize.y / 2 };

    int projectilesAmount = 0;
    float radius = 200.f;
    float projTimer = 0.2f;
    bool spiralIsDone = false;

    /// @brief Spawns the projectiles in the circle.
    void SpawnCircle();

    /// @brief Handles the spiral movement of the projectiles.
    /// @param deltaTime The time elapsed since the last frame update.
    void SpiralCircle(float deltaTime);

    /// @brief Moves a projectile towards the center.
    /// @param proj A pointer to the projectile to move.
    /// @param deltaTime The time elapsed since the last frame update.
    void MoveProjToCenter(SphereProjectile* proj, float deltaTime);
};
