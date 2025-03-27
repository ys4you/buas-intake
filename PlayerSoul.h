#pragma once
#include <utility>

#include "GameObject.h"

/// @brief A class representing the player's soul or character in the game.
/// This class extends GameObject and adds health management features like taking damage, dying, and healing.
/// It is responsible for tracking the player's health and rendering the player's soul UI.
class PlayerSoul : public GameObject
{
public:
    /// @brief Constructs a PlayerSoul with specified parameters.
    /// @param screen The surface where the object will be drawn.
    /// @param pos The initial position of the PlayerSoul. Default is { 0, 0 }.
    /// @param objSize The size of the PlayerSoul. Default is { 1, 1 }.
    /// @param filePath The file path of the sprite for the PlayerSoul. Default is "" (empty).
    /// @param objName The name of the object. Default is "PlayerSoul".
    /// @param maxHealth The maximum health the PlayerSoul can have. Default is 100.
    /// @param health The current health of the PlayerSoul. Default is 100.
    /// @param collider The collider associated with the PlayerSoul. Default is a collider of type AABB.
	PlayerSoul(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "",
        const std::string& objName = "PlayerSoul",
        int maxHealth = 100,        // Default max health
        int health = 100,           // Default current health
        Collider collider = Collider(ColliderType::AABB)

    )
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName,
            collider),
          healthPoints(health),
          maxHealthPoints(maxHealth)
    {
    }

    /// @brief Reduces health by the specified amount of damage.
    /// @param damageAmount The amount of damage to be taken.
    void TakeDamage(int damageAmount);
    /// @brief Handles the death of the PlayerSoul (game over).
    void Die();
    /// @brief Increases the health of the PlayerSoul by the specified amount.
    /// @param healAmount The amount of health to restore.
    void Heal(int healAmount);

    bool hasDied = false;

    int healthPoints;
    int maxHealthPoints;

private:
    /// @brief Updates the PlayerSoul's state, such as checking if the PlayerSoul has died.
    /// @param deltaTime The time passed since the last update.
    void Update(float deltaTime) override;

    glm::vec2 positionOfUI = { 100.f,20.f };
};