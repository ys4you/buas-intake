#include "precomp.h"
#include "Character.h"

void Character::Heal(int amount)
{
	healthPoints =+ amount;

	if (healthPoints > maxHealthPoints)
	{
		healthPoints = maxHealthPoints;
	}
}

void Character::TakeDamage(int amount)
{
	healthPoints =- amount;

	if (healthPoints <= 0)
	{
		Die();
	}
}

void Character::Die()
{
	//TODO: inplement what to do when die
}
