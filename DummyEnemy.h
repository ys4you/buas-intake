#pragma once
#include "BaseAttack.h"
#include "Enemy.h"
#include "GameObject.h"

//attacks
#include "DummyAttackOne.h"
#include "CircleAttack.h"
#include "DiamondRain.h"
#include "RandomBlasterSpam.h"

enum class TurnState
{
	None,
	Waiting 
};


class DummyEnemy : public Enemy
{
public:
    DummyEnemy(
        Surface* screen,
        Box* box = nullptr,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "assets/art/enemy/dummy/dummy-Sheet.png",
        const std::string& objName = "Dummy")
        : Enemy(
            screen,
            5,
            5,
            8,
            pos,
            objSize,
            std::move(filePath),
            objName) // Calling the base class constructor
    {
        glm::vec2 p = box->GetPosition();
        glm::vec2 s = box->GetSize();

        std::cout << "Box Position: (" << p.x << ", " << p.y << ")\n";
        std::cout << "Box Size: (" << s.x << ", " << s.y << ")\n";
        attacks.push_back(new DummyAttackOne(screen, 15, 10.f));

        attacks.push_back(new CircleAttack(screen, 10.f, 10, amountOfCircles));

        attacks.push_back(new RandomBlasterSpam(screen, 10.f, 1.f, box));

        if (box != nullptr)
			attacks.push_back(new DiamondRain(screen, 10.f, 0.2f, 0.5f, box));
    }
    ~DummyEnemy();

    vector<BaseAttack*> attacks;

    void Update(float deltaTime) override;
    void Attack();

    bool IsDone() { return isDone; }
    void SetDone(bool newState);
    
protected:
    bool isAttacking = false;
    bool isDone = false;
    int attackIteration = 0; 
    int amountOfCircles = 3;
    void UseSequenceAttack();
    void UseDefinedAttack(BaseAttack* attack);
};

