#pragma once

#include <vector>

#include "BaseAttack.h"
#include "SphereProjectile.h"
#include "Circle.h"

// ReSharper disable once CppInconsistentNaming
class CircleAttack : public BaseAttack
{
public:
    CircleAttack(Surface* screen, int duration, int amountOfProj,  int amountOfCircles = 1);
    ~CircleAttack();

    void ResetAttack() override;
    void Update(float deltaTime) override;
    void FireAttack() override;


private:
    //spawning naccesaries
    std::vector<Circle*> circles;

    glm::vec2 projSize = { 64, 64 };
    glm::vec2 center = { 640 - projSize.x / 2, 240 - projSize.y / 2 };
    int projectilesAmount = 0;
    int circleAmount = 0;
    float radius = 0;
	//attack vars
    int startingIndex = 0;

    int activeCircleIndex = 0;


    //functions
    void UpdateCircles(float deltaTime);

    void SpawnCircle(Circle circle);
};
