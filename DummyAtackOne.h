#pragma once

#include <vector>
#include "SphereProjectile.h"

class DummyAtackOne
{
public:
    DummyAtackOne(Surface* screen, int amount)
        : screen(screen), projectilesAmount(amount)
    {
        projectiles.reserve(projectilesAmount);
        for (int i = 0; i < projectilesAmount; ++i)
        {
            //SphereProjectile* projectile = new SphereProjectile(screen);
            //add projectile to vector.
            //TODO: ERROR: Instantiating the projectiles like so will cause the program to crash on destruct
        }
    }

    // Methods
    bool DoingAttack();
    void Update(float deltaTime);

private:
    Surface* screen;
    int projectilesAmount;
    std::vector<SphereProjectile> projectiles; // Change from std::array to std::vector

    float attackTime = 10.f; // in seconds
    float timer = 0.f;
    bool isAttacking = false;
};
