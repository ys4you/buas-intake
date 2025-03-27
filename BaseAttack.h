#pragma once
#include <iostream>

/// @class BaseAttack
/// @brief Base class for attack mechanics in a game.
/// 
/// This class provides a foundation for implementing attack actions.
/// It includes mechanisms for attack duration, intervals, and status tracking.
class BaseAttack
{
public:

    /// @brief Constructs a BaseAttack object.
    /// @param screen Pointer to the screen where the attack is displayed.
    /// @param duration Duration of the attack in seconds.
    /// @param interval Time between attack activations in seconds.
    BaseAttack(Surface* screen, float duration, float interval) :
        screen(screen),
        attackTime(duration),
        interval(interval)
    {
    }

    /// @brief Sets the interval of the attack.
    /// @param newInterval A float representing the new interval value.
    void SetInterval(float newInterval) { interval = newInterval; }

    /// @brief Gets the current interval.
    /// @return Returns the current interval value as a float.
    float GetInterval() { return interval; }

    /// @brief Virtual destructor for BaseAttack.
    virtual ~BaseAttack() = default;

    /// @brief Triggers the attack.
    /// 
    /// This function starts the attack, setting `isAttacking` to true
    /// and incrementing the attack timer.
    virtual void FireAttack()
    {
        isAttacking = true;
        timer += 0.01f;
    }

    /// @brief Checks if the attack is still active.
    /// @return Returns true if the attack is still in progress; otherwise, false.
    virtual bool DoingAttack()
    {
        // std::cout << "Timer: " << std::to_string(timer) << " isAttacking" << isAttacking << std::endl;
        return isAttacking && timer > 0;
    }

    /// @brief Resets the attack state.
    /// 
    /// This function stops the attack and resets the attack timer.
    virtual void ResetAttack()
    {
        isAttacking = false;
        timer = 0;
    }

    /// @brief Updates the attack state.
    /// @param deltaTime The time elapsed since the last update.
    virtual void Update(float deltaTime) = 0;

    Surface* screen;

protected:
    float attackTime = 0.01f;

    float interval = 0.f;

    float timer = 0.f;

    bool isAttacking = false;

    bool isDestroying = false;
};
