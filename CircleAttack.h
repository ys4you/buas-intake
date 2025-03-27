#pragma once

#include <vector>

#include "BaseAttack.h"
#include "SphereProjectile.h"
#include "Circle.h"

// ReSharper disable once CppInconsistentNaming

/// @brief An attack that spawns circles and launches projectiles in a circular pattern.
class CircleAttack : public BaseAttack {
public:
    /// @brief Constructor to initialize the attack.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param duration The duration of the attack.
    /// @param amountOfProj The number of projectiles per circle.
    /// @param amountOfCircles The number of circles to spawn (default is 1).
    CircleAttack(Surface* screen, float duration, int amountOfProj, int amountOfCircles = 1);

    /// @brief Destructor for CircleAttack.
    ~CircleAttack();

    /// @brief Resets the attack state.
    void ResetAttack() override;

    /// @brief Updates the attack logic.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;

    /// @brief Triggers the attack, spawning projectiles in a circular pattern.
    void FireAttack() override;

private:
    // Spawning necessities
    std::vector<Circle*> circles;

    glm::vec2 projSize = { 64, 64 };
    glm::vec2 center = { 640 - projSize.x / 2, 240 - projSize.y / 2 };
    int projectilesAmount = 0;
    int circleAmount = 0;
    float radius = 0;

    // Attack variables
    int startingIndex = 0;
    int activeCircleIndex = 0;

    /// @brief Updates the circles during the attack phase.
    /// @param deltaTime The time elapsed since the last frame update.
    void UpdateCircles(float deltaTime);

    /// @brief Spawns a new circle.
    /// @param circle The circle to spawn.
    void SpawnCircle(Circle circle);
};
