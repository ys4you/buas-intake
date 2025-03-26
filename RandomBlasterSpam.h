#pragma once
#include "BaseAttack.h"
#include "GameObject.h"
#include "Blaster.h"
#include "Box.h"

class RandomBlasterSpam : public BaseAttack
{
public:
	RandomBlasterSpam(Surface* screen, int duration, float interval, Box* box);
	~RandomBlasterSpam();

	void ResetAttack() override;
	void Update(float deltaTime) override;
	void FireAttack() override;


private:
	vector<Blaster*> blasters;
	Box* box = nullptr;

	//timers
	float SpawnCooldown = 0;
};