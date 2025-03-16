#pragma once
class BaseAttack
{
public:

	BaseAttack(Surface* screen, int duration) :
	screen(screen),
	attackTime(duration)
	{
	}
	
	virtual ~BaseAttack() = default;

	virtual void FireAttack()
	{
		isAttacking = true;
		timer += 0.01f;
	}

	virtual bool DoingAttack()
	{
		return isAttacking && timer <= 0;
	}
	virtual void ResetAttack()
	{
		isAttacking = false;
		timer = 0;
	}
	virtual void Update(float deltaTime) = 0;

	Surface* screen;
protected:
	float attackTime;

	float timer = 0.f;
	bool isAttacking = false;
	bool isDestroying = false;
};