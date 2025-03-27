#pragma once

#include <vector>
#include <random>

#include "BaseAttack.h"
#include "SphereProjectile.h"

class DummyAttackOne : public BaseAttack
{
public:
    ~DummyAttackOne() override;

	void ResetAttack() override;
    DummyAttackOne(Surface* screen, int amount, float duration);
    void Update(float deltaTime);

private:
    int projectilesAmount;
    std::vector<SphereProjectile*> projectiles;

};
