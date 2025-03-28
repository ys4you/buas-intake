#include "precomp.h"
#include "Enemy.h"


void Enemy::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Enemy::TakeDamage(int amount)
{
	std::cout << "enemy took damage\n";
	healthPoints -= amount;
	std::cout << "new health points: " << healthPoints << std::endl;

	if (healthPoints <= 0)
	{
		Die();
	}
}

void Enemy::Die()
{
	std::cout << "enemy Died\n";
	isEnemyDead = true;
}