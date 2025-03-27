#pragma once
#include "BaseAttack.h"
#include "GameObject.h"
#include "Blaster.h"
#include "Box.h"

/// @brief A random blaster spam attack, spawning projectiles at random intervals.
class RandomBlasterSpam : public BaseAttack {
public:
    /// @brief Constructor to initialize the attack.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param duration The duration of the attack.
    /// @param interval The time interval between each blaster spawn.
    /// @param box A pointer to the Box object, which may affect attack behavior.
    RandomBlasterSpam(Surface* screen, float duration, float interval, Box* box);

    /// @brief Destructor for RandomBlasterSpam.
    ~RandomBlasterSpam();

    /// @brief Resets the attack state.
    void ResetAttack() override;

    /// @brief Updates the attack logic.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;

    /// @brief Fires the attack, spawning random blasters at intervals.
    void FireAttack() override;

private:
    // List of blasters spawned during the attack.
    vector<Blaster*> blasters;

    // A pointer to the Box object, which may affect the blaster spawn behavior.
    Box* box = nullptr;

    // Timer variables for controlling spawn intervals.
    float SpawnCooldown = 0;
};
