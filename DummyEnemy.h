#pragma once
#include "BaseAttack.h"
#include "Enemy.h"
#include "GameObject.h"

//attacks
#include "DummyAttackOne.h"
#include "CircleAttack.h"
#include "DiamondRain.h"
#include "RandomBlasterSpam.h"


/// @brief Represents a dummy enemy that can perform various attacks.
class DummyEnemy : public Enemy
{
public:
    /// @brief Constructor for the DummyEnemy class.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param box A pointer to the Box object for collision (default is nullptr).
    /// @param pos The position of the enemy (default is {0, 0}).
    /// @param objSize The size of the enemy (default is {1, 1}).
    /// @param filePath The file path for the texture (default is "assets/art/enemy/dummy/dummy-Sheet.png").
    /// @param objName The name of the object (default is "Dummy").
    DummyEnemy(
        Surface* screen,
        Box* box = nullptr,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        std::string filePath = "assets/art/enemy/dummy/dummy-Sheet.png",
        const std::string& objName = "Dummy")
        : Enemy(
            screen,
            9,
            9,
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

    /// @brief Destructor for the DummyEnemy class.
    ~DummyEnemy();

    vector<BaseAttack*> attacks;

    /// @brief Updates the DummyEnemy object, including its state and actions.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;

    /// @brief Executes the attack sequence.
    void Attack();

    /// @brief Checks if the DummyEnemy has finished its attacks.
    /// @return A boolean value indicating if the enemy is done with attacks.
    bool IsDone() { return isDone; }

    /// @brief Sets the current state of the DummyEnemy (whether it is done with attacks).
    /// @param newState The new state to set.
    void SetDone(bool newState);

protected:
    bool isAttacking = false;
    bool isDone = false;
    int attackIteration = 0;
    int amountOfCircles = 3;

    /// @brief Executes the attack sequence in order.
    void UseSequenceAttack();

    /// @brief Executes a specific defined attack.
    /// @param attack A pointer to the BaseAttack to perform.
    void UseDefinedAttack(BaseAttack* attack);
};
