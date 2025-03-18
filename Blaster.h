#pragma once
#include <random>

#include "Box.h"
#include "GameObject.h"
#include "Blast.h"

struct BlastPos
{
    float x1, x2, y1, y2;
};

class Blaster : public GameObject
{
public:

    Blaster(
        Surface* screen,
        Box* box = nullptr,
        const glm::vec2& pos = { 0, 0 },
        const glm::vec2& objSize = { 64, 64 },
        std::string filePath = "assets/art/enemy/dummy/diamond.png",
        const std::string& objName = "Blaster")
        : GameObject(
            screen,
            pos,
            1,
            objSize,
            std::move(filePath),
            objName), box(box)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        uniform_int_distribution<> dist(0, 3);

    	randomDir = dist(gen);
    	//randomDir = 3;
        SpawnBlasterAtPlayer();
    }
    ~Blaster();

    bool isBlastDOne = false;

    void Update(float deltaTime) override;

private:

    Box* box = nullptr;
    glm::vec2 playerPos = { 0,0 };

	int randomDir = -1;

    //timer
    float SpawnCooldown = 2.f;
    float blastCooldown = 0.25f;

    //blast
    Blast* blast = nullptr;
    glm::vec2 blastSize = { 0,0 };

    void SpawnBlasterAtPlayer();
    void FireBlast(float deltaTime);
};