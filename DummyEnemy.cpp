#include "precomp.h"
#include "DummyEnemy.h"

void DummyEnemy::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

}

void DummyEnemy::UseRandomAttack(BaseAttack* attack)
{
	attack->FireAttack();

	while (attack->DoingAttack())
	{
		
	}
}
