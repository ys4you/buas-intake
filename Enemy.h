#pragma once
#include "GameObject.h"

/// @brief Represents an enemy in the game, extending from GameObject.
/// Handles health, damage, and interactions with the player.
class Enemy : public GameObject
{
public:
    /// @brief Constructor to initialize an enemy object.
    /// @param screen The screen on which the object will be rendered.
    /// @param maxHealthPoints The maximum health the enemy can have.
    /// @param healthPoints The current health of the enemy.
    /// @param frames The number of frames for the sprite (default 1).
    /// @param pos The initial position of the enemy.
    /// @param objSize The size of the enemy object.
    /// @param filePath Path to the sprite image.
    /// @param objName The name of the object.
    Enemy(
        Surface* screen,
        int maxHealthPoints,
        int healthPoints,
        int frames = 1,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "Character")
        : GameObject(
            screen,
            pos,
            frames,
            objSize,
            std::move(filePath),
            objName), // Calling the base class constructor
        maxHealthPoints(maxHealthPoints), healthPoints(healthPoints), damage(0)
    {
        std::cout << "Enemy health points: " << healthPoints << std::endl;
    }

    int maxHealthPoints = 0;
    int healthPoints = 0;

    int damage = 0;

    bool isEnemyDead = false;

    /// @brief Updates the enemy's state, called every frame.
    /// @param deltaTime Time passed since the last frame.
    void Update(float deltaTime) override;
    /// @brief Reduces the enemy's health by a given amount.
    /// @param amount The amount of damage to be taken.
    void TakeDamage(int amount);

    /// @brief Handles the enemy's death, typically when health reaches zero.
    void Die();
    ///@brief Returns the alive state of the enemy
    bool isDead() const { return isEnemyDead; }
};
