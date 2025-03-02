#pragma once

#include <map> // Include for std::map

class GameObject; // Forward declaration, does not need full definition

class GameObjectManager {
public:
    static GameObjectManager& Get();

    static void RegisterGameObject(GameObject* newGameObj);

    GameObject* GetGameObject(int id);

    void RemoveGameObject(int id);

    static void UpdateAllObjects(float deltaTime);

    static void Deconstruct(); // Cleans up all game objects

private:
    GameObjectManager() = default;
    ~GameObjectManager() = default;

    // Disable copy and assignment
    GameObjectManager(const GameObjectManager&) = delete;
    GameObjectManager& operator=(const GameObjectManager&) = delete;

    // In the .h file, declare the static variables
    static int nextId; // Tracks the next available ID
    static std::map<int, GameObject*> gameObjects; // Store objects by ID using std::map
};
