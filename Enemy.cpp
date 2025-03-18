#include "precomp.h"
#include "Enemy.h"


void Enemy::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Enemy::TakeDamage(int amount)
{
	healthPoints = -amount;

	if (healthPoints <= 0)
	{
		Die();
	}
}

void Enemy::Die()
{
	//TODO: inplement what to do when die
}