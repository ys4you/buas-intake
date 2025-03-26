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
    circles.reserve(circleAmount);
	for (int i = 0; i < circleAmount; ++i)
	{
        circles.push_back(new Circle(screen, projectilesAmount));
	}

}

CircleAttack::~CircleAttack()
{
	for (auto circle : circles)
	{
		if (circle != nullptr)
		{
            delete circle;
		}
	}
}


void CircleAttack::ResetAttack()
{
	BaseAttack::ResetAttack();
    startingIndex = 0;
    activeCircleIndex = 0;
    std::vector<Circle*> v;
    circles = v;
    circles.reserve(circleAmount);
    for (int i = 0; i < circleAmount; ++i)
        circles.push_back(new Circle(screen, projectilesAmount));
}

void CircleAttack::Update(float deltaTime)
{
    if (isDestroying)
        return;

    if (!isAttacking)
        return;

    if (timer <= attackTime)
    {
        timer += deltaTime / 1000.f;
		UpdateCircles(deltaTime);
    }
    else
    {
        ResetAttack();
    }
}

void CircleAttack::FireAttack()
{
	BaseAttack::FireAttack();
}

void CircleAttack::UpdateCircles(float deltaTime)
{
    if (circles.empty())
        return;

    for (int i = 0; i <= activeCircleIndex; ++i)
    {
        if (i < circles.size() && circles[i])
        {

	        if (circles[i]->projectiles.empty())
	        {
                circles[i]->SpawnCircle();
	        }
            circles[i]->SpiralCircle(deltaTime);
        }
    }

    if (activeCircleIndex < circles.size() && circles[activeCircleIndex]->spiralIsDone)
    {
        activeCircleIndex++;
    }
}