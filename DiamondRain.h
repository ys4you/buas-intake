#pragma once
#include "BaseAttack.h"
#include "Box.h"
#include "DiamondProjectile.h"

class DiamondRain : public BaseAttack
{
public:
	DiamondRain(Surface* screen, float duration, float interval, float bulletSpeed, Box* box, bool goingUp = true);
	~DiamondRain();

	void Update(float deltaTime) override;

private:
	float speed = 0.5f;
	bool goingUp = true;
	glm::vec2 playerPos = {0,0};
	Box* box = nullptr;
	float SpawnCooldown = 0.f;
	vector<DiamondProjectile*> projectiles;
};

