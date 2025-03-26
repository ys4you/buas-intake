#include "precomp.h"
#include "RandomBlasterSpam.h"



RandomBlasterSpam::RandomBlasterSpam(Surface* screen, int duration, float interval,  Box* box)
	: BaseAttack(screen, duration, interval), box(box)

{
}

RandomBlasterSpam::~RandomBlasterSpam()
{
	isDestroying = true;
	for (auto blaster : blasters)
	{
		if (blaster != nullptr)
		{
			blaster->MarkForDeletion();
		}
	}
}

void RandomBlasterSpam::ResetAttack()
{
	BaseAttack::ResetAttack();
}

void RandomBlasterSpam::Update(float deltaTime)
{
	if(isDestroying)
		return;

	if (!isAttacking)
		return;

	timer += deltaTime / 1000.f;

	if(SpawnCooldown <= 0)
	{
		//std::cout << "spawn a new blaster\n";
		new Blaster(screen, box);
		SpawnCooldown = interval;
	}
	else
	{
		//std::cout << "SpawnCooldown at: " << SpawnCooldown << std::endl;;

		SpawnCooldown -= deltaTime / 1000.f;
	}

	if(timer >= attackTime)
	{
		ResetAttack();
	}
}

void RandomBlasterSpam::FireAttack()
{
	BaseAttack::FireAttack();
}
