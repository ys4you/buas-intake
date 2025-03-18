#pragma once
#include "GameObject.h"
#include "PlayerSoul.h"

class Blast : public GameObject
{
public:
    Blast(
        Surface* screen,
        const glm::vec2& pos = { 0,0 },
        const glm::vec2& objSize = { 0, 0},
        int randomDir = -1,
        std::string filePath = "assets/art/enemy/dummy/pixel.png",
        const std::string& objName = "Blast",
        Collider collider = Collider(ColliderType::AABB))
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName,
            collider), randomDir(randomDir)
    {
        playerObj = GameObjectManager::Get().GetGameObjectByName("PlayerSoul");
    }

private:
    GameObject* playerObj = nullptr;
    PlayerSoul* player = nullptr;
    int randomDir = -1;

    void CollisionCheck();
    void Render() override;
    void Update(float deltaTime) override;
};

