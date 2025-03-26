#pragma once
#include "SphereProjectile.h"

class Circle
{
public:

	Circle(Surface* screen, int amountOfProjectiles) : screen(screen), projectilesAmount(amountOfProjectiles)
	{
		
	}
	~Circle();
	Surface* screen;
	std::vector<SphereProjectile*> projectiles;
	glm::vec2 projSize = { 64, 64 };
	glm::vec2 center = { 640 - projSize.x / 2, 240 - projSize.y / 2 };

	int projectilesAmount = 0;
	float radius = 200.f;
	float projTimer = 0.2f;
	bool spiralIsDone = false;


	void SpawnCircle();

	void SpiralCircle(float deltaTime);

	void MoveProjToCenter(SphereProjectile* proj, float deltaTime);

};
