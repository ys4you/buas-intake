#include "precomp.h"
#include "CircleAttack.h"

#include <random>

CircleAttack::CircleAttack(Surface* screen, int duration, int amountOfProj, int amountOfCircles)
    : BaseAttack(screen, duration, 0), projectilesAmount(amountOfProj), circleAmount(amountOfCircles), radius(200.f)
{
	if (circleAmount == 0)
	{
        std::cout << "CircleAttack initialized without circleAmount. Plaese give in a valid Amount\n";
        return;
	}
    //reserves the right amount 
    circles.reserve(circleAmount);
	for (int i = 0; i < circleAmount; ++i)
	{
        circles.push_back(new Circle(screen, projectilesAmount));

        circles[i]->projectiles.reserve(amountOfProj);
        circles[i]->SpawnCircle();
	}

}




void CircleAttack::ResetAttack()
{
	BaseAttack::ResetAttack();
    startingIndex = 0;
}



void CircleAttack::Update(float deltaTime)
{
    if (isDestroying)
        return;

    if (!isAttacking)
        return;

    UpdateCircles(deltaTime);
}

void CircleAttack::FireAttack()
{
	BaseAttack::FireAttack();

    std::random_device rd;
    std::mt19937 gen(rd());
    uniform_int_distribution<> dist(0, projectilesAmount);

    startingIndex = dist(gen);
}

void CircleAttack::UpdateCircles(float deltaTime)
{
    if (circles.empty())
        return;

    for (int i = 0; i <= activeCircleIndex; ++i)
    {
        if (i < circles.size() && circles[i])
        {
            circles[i]->SpiralCircle(deltaTime);
        }
    }

    if (activeCircleIndex < circles.size() && circles[activeCircleIndex]->spiralIsDone)
    {
        activeCircleIndex++;
    }
}

