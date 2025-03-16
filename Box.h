#pragma once
#include "GameObject.h"
class Box : public GameObject
{
public:
    Box(
        Surface* screen,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 1, 1 },
        const std::string& objName = "Box",
        Collider collider = Collider(ColliderType::AABB))
        : GameObject(
            screen,
            pos,
            objSize,
            "",
            objName,
            collider) // Calling the base class constructor
    {
    }

    void Update(float deltaTime) override;

    void Render() override;
};