#pragma once

#include <map>
#include <string>

class GameObject;

class GameObjectManager
{
public:
    static GameObjectManager& Get();

    void RegisterGameObject(GameObject* newGameObj);
    GameObject* GetGameObject(int id);
    GameObject* GetGameObjectByName(const std::string& name);
    void RemoveGameObject(int id);
    void UpdateAllObjects(float deltaTime);

private:
    GameObjectManager();
    ~GameObjectManager();

    int nextId;
    std::map<int, GameObject*> gameObjects;

    GameObjectManager(const GameObjectManager&) = delete;
    GameObjectManager& operator=(const GameObjectManager&) = delete;
};
