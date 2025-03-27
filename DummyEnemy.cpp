#include "precomp.h"
#include "DummyEnemy.h"

DummyEnemy::~DummyEnemy()
{
	for (auto attack : attacks)
	{
		delete attack;
	}
	attacks.clear(); 
}

void DummyEnemy::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	for (auto attack : attacks)
	{
		attack->Update(deltaTime);
	}

}

void DummyEnemy::Attack()
{

	if (attackIteration < attacks.size())
	{
		UseSequenceAttack();
	}
	else
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distribute(0, attacks.size() - 1);
		UseDefinedAttack(attacks[distribute(gen)]);
	}

	//UseDefinedAttack(attacks[1]);
}


void DummyEnemy::SetDone(bool newState)
{
	isDone = newState;
}

void DummyEnemy::UseSequenceAttack()
{
	if (!isAttacking)
	{
		isAttacking = true;
		attacks[attackIteration]->FireAttack();
		std::cout << "Starting attack " << attackIteration << "\n";
		SetDone(false);
	}

	if (!attacks[attackIteration]->DoingAttack())
	{
		std::cout << "Attack " << attackIteration << " ended.\n";

		if (attackIteration < 3)
		{
			attackIteration++;
		}
		SetDone(true);
		attacks[attackIteration]->ResetAttack();
		isAttacking = false;
	}
}

void DummyEnemy::UseDefinedAttack(BaseAttack* attack)
{
	if (!isAttacking)
	{
		isAttacking = true;
		attack->FireAttack();
		SetDone(false);
	}

	if (!attack->DoingAttack())
	{
		SetDone(true);
		attack->ResetAttack();
		isAttacking = false;
	}
}