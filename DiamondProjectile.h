#pragma once
#include "GameObject.h"
#include "Projectile.h"

class DiamondProjectile : public Projectile
{
public:
    DiamondProjectile(
        Surface* screen,
        float speed = 0.f,
        const glm::vec2& pos = { 0,0 },
        bool goingUp = true,
        const glm::vec2& objSize = { 32, 64 },
        std::string filePath = "assets/art/enemy/dummy/sharpDiamond.png",
        const std::string& objName = "DiamondProjectile",
        Collider collider = Collider(ColliderType::AABB))
        : Projectile(
            screen,
            pos,
            objSize,
            goingUp ? -speed : speed, // Ternary operator 
            std::move(filePath),
            objName,
            collider), goingUp(goingUp)
    {
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

private:
    void Update(float deltaTime) override;
	bool goingUp = true;
};

