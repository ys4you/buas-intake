#include "precomp.h"
#include "DiamondRain.h"

#include <random>


DiamondRain::DiamondRain(Surface* screen, float duration, float interval, float bulletSpeed, Box* box, bool goingUp)
	: BaseAttack(screen, duration, interval), speed(bulletSpeed), box(box), goingUp(goingUp)
{
	SpawnCooldown = interval;
}


DiamondRain::~DiamondRain()
{
	for (auto diamond : projectiles)
	{
		if (diamond != nullptr)
		{
			diamond->MarkForDeletion();
		}
	}
}

void DiamondRain::Update(float deltaTime)
{
	//if (isDestroying)
	//	return;

	//if (!isAttacking)
	//	return;

	timer += deltaTime / 1000.f;

	std::random_device rd;
	std::mt19937 gen(rd());

	if (SpawnCooldown <= 0)
	{
		glm::vec2 boxPos = box->GetPosition();
		glm::vec2  boxSize = box->GetSize();
		std::uniform_real_distribution<float> dist(boxPos.x, boxPos.x + boxSize.x);

		float randomX = dist(gen);
		//std::cout << "randomX: " << randomX << std::endl;
		//std::cout << "spawn a new diamond\n";
		float offset = 15.f;
		float yPos = goingUp ? (boxPos.y + boxSize.y + offset) : (boxPos.y - offset - 64);
		DiamondProjectile* d = new DiamondProjectile(screen, speed, { randomX, yPos }, goingUp);

		projectiles.push_back(d);
		SpawnCooldown = interval;
	}
	else
	{
		//std::cout << "SpawnCooldown at: " << SpawnCooldown << std::endl;
		SpawnCooldown -= deltaTime / 1000.f;
	}

	if (timer >= 20.f)
	{
		ResetAttack();
	}
}