#pragma once
#include <random>

#include "Box.h"
#include "GameObject.h"
#include "Blast.h"

struct BlastPos
{
    float x1, x2, y1, y2;
};

/// @brief Represents a Blaster object that fires blasts at the player.
class Blaster : public GameObject {
public:
    /// @brief Constructor to initialize the Blaster object.
    /// @param screen A pointer to the Surface object for rendering.
    /// @param box A pointer to the Box object (default is nullptr).
    /// @param pos The position of the object (default is {0, 0}).
    /// @param objSize The size of the object (default is {64, 64}).
    /// @param filePath The file path for the texture (default is "assets/art/enemy/dummy/diamond.png").
    /// @param objName The name of the object (default is "Blaster").
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
        playerPos = GameObjectManager::Get().GetGameObjectByName("PlayerSoul")->GetPosition();
        std::random_device rd;
        std::mt19937 gen(rd());
        uniform_int_distribution<> dist(0, 3);

        randomDir = dist(gen);
        SpawnBlasterAtPlayer();
    }

    ~Blaster();

    /// @brief Flag indicating if the blast is done.
    bool isBlastDOne = false;

    /// @brief Updates the Blaster object.
    /// @param deltaTime The time elapsed since the last frame update.
    void Update(float deltaTime) override;

private:
    Box* box = nullptr;
    glm::vec2 playerPos = { 0, 0 };

    int randomDir = -1;

    // Timer variables
    float SpawnCooldown = 2.f;
    float blastCooldown = 0.25f;

    // Blast-related variables
    Blast* blast = nullptr;
    glm::vec2 blastSize = { 0, 0 };

    /// @brief Spawns the blaster at the player's position.
    void SpawnBlasterAtPlayer();

    /// @brief Fires a blast towards the player.
    void FireBlast();
};
