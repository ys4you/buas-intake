#pragma once
#include "BaseAttack.h"
#include "Box.h"
#include "DiamondProjectile.h"

/// @brief A diamond rain attack that spawns diamond projectiles at regular intervals.
class DiamondRain : public BaseAttack {
public:
    /// @brief Constructor to initialize the DiamondRain attack.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param duration The duration of the attack.
    /// @param interval The time interval between spawning projectiles.
    /// @param bulletSpeed The speed at which the projectiles move.
    /// @param box A pointer to the Box object, which may affect attack behavior.
    /// @param goingUp A boolean indicating the direction of the attack (default is true).
    DiamondRain(Surface* screen, float duration, float interval, float bulletSpeed, Box* box, bool goingUp = true);

    /// @brief Destructor for DiamondRain.
    ~DiamondRain();

    /// @brief Updates the attack logic and spawns projectiles at intervals.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;

private:
    float speed = 0.5f;

    bool goingUp = true;

    glm::vec2 playerPos = {0, 0};

    Box* box = nullptr;

    float SpawnCooldown = 0.f;

    vector<DiamondProjectile*> projectiles;
};
