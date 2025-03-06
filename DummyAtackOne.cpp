#include "precomp.h"
#include "DummyAtackOne.h"

bool DummyAtackOne::DoingAttack()
{
	isAttacking = true;
	timer =+ 0.01f;
	return isAttacking && timer <= 0;
}

void DummyAtackOne::Update(float deltaTime)
{
	std::cout << timer << std::endl;

	if (isAttacking)
	{
		timer =+ (deltaTime/1000.f);
		if (timer <= attackTime)
		{
			
		}
		else
		{
			isAttacking = false;
			timer = 0;
		}
	}
	else
	{
		
	}
}
