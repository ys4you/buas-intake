#pragma once
#include "GameObject.h"
#include "common.h"
#include "PlayerSoul.h"

class SphereProjectile : public GameObject
{
public:
    SphereProjectile(
        Surface* screen,
        const glm::vec2& pos = { 0,0 },
        const glm::vec2& objSize = { 32, 32 },
        float angle = 0,
        std::string filePath = "assets/art/enemy/dummy/bullet.png",
        const std::string& objName = "SphereProjectile",
        Collider collider = Collider(ColliderType::AABB))
        :  GameObject(
            screen,
            pos,
            objSize,
            std::move(filePath),
            objName,
            collider),angle(angle)
    {
        //std::cout << "Spawned Sphere(" << Id << ") at position: x: " << position.x << " y: " << position.y << std::endl;
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

    float angle = 0;
    float speed = 500.f;
    float timer = 0.f;
    bool shouldRender = true;
    glm::vec2 initialDirection = glm::vec2(0.f, 0.f);

    GameObject* playerObj = nullptr;
    PlayerSoul* player = nullptr;

    void Test();
    void Update(float deltaTime) override;

    void Render() override;
};

