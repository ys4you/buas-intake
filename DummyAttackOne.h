#pragma once

#include <vector>
#include <random>

#include "BaseAttack.h"
#include "SphereProjectile.h"

class DummyAttackOne : public BaseAttack
{
public:
    DummyAttackOne(Surface* screen, int amount, int duration);
    ~DummyAttackOne() override;

	void ResetAttack() override;
    void Update(float deltaTime);

private:
    int projectilesAmount;
    std::vector<SphereProjectile*> projectiles;

};
