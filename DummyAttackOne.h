#pragma once

#include <vector>
#include <random>

#include "BaseAttack.h"
#include "SphereProjectile.h"

/// @brief A specific attack pattern used by the Dummy enemy, launching sphere projectiles.
class DummyAttackOne : public BaseAttack {
public:
    /// @brief Destructor for DummyAttackOne.
    ~DummyAttackOne() override;

    /// @brief Resets the attack state.
    void ResetAttack() override;

    /// @brief Constructor to initialize the attack.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param amount The number of projectiles to spawn.
    /// @param duration The duration of the attack.
    DummyAttackOne(Surface* screen, int amount, float duration);

    /// @brief Updates the attack logic.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime);

private:
    int projectilesAmount;
    std::vector<SphereProjectile*> projectiles;
};
