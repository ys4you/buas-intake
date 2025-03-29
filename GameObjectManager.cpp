#include "precomp.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include <iostream>
#include <string>

GameObjectManager& GameObjectManager::Get()
{
    static GameObjectManager instance;
    return instance;
}

GameObjectManager::GameObjectManager() : nextId(0) {}

GameObjectManager::~GameObjectManager()
{
    for (auto& pair : gameObjects)
    {
	    if (!pair.second) //TODO: See doc how to check if pair is not null and not just .second
        delete pair.second;
    }
    gameObjects.clear();
}

void GameObjectManager::RegisterGameObject(GameObject* newGameObj)
{
    if (!newGameObj) return;

    int id = nextId++;
    newGameObj->SetId(id);

    gameObjects[id] = newGameObj;

    std::string logMessage = "GameObject Created: " + newGameObj->GetName() + " (ID: " + std::to_string(id) + ")\n";
#ifdef _DEBUG
    OutputDebugStringA(logMessage.c_str());
#endif

    std::cout << logMessage;
}

GameObject* GameObjectManager::GetGameObject(int id)
{
    auto it = gameObjects.find(id);
    return (it != gameObjects.end()) ? it->second : nullptr;
}

GameObject* GameObjectManager::GetGameObjectByName(const std::string& name)
{
    for (auto& pair : gameObjects)
    {
        if (pair.second->GetName() == name)
        {
            return pair.second;
        }
    }
    return nullptr;
}

void GameObjectManager::RemoveGameObject(int id)
{
    auto it = gameObjects.find(id);
    if (it != gameObjects.end())
    {
        const std::string logMessage = "GameObject Removed: " + it->second->GetName() + " (ID: " + std::to_string(id) + ")\n";

        std::cout << logMessage << std::endl;
#ifdef _DEBUG
        OutputDebugStringA(logMessage.c_str());
#endif

        delete it->second;  // Free memory
        gameObjects.erase(it);  // Remove from map
    }
}



void GameObjectManager::UpdateAllObjects(float deltaTime)
{
    if (gameObjects.empty())
        return;

    for (auto it = gameObjects.begin(); it != gameObjects.end(); )
    {
        if (!it->second || it->second->ShouldBeRemoved())
        {
            it = gameObjects.erase(it); // erase returns the next valid iterator
        }
        else
        {
            ++it;
        }
    }

    for (auto& [id, gameObj] : gameObjects)
    {
        if (!gameObj)
            continue;

        //std::cout << "Updating GameObject: " << gameObj->GetName() << std::endl;
        gameObj->Update(deltaTime);
    }
}


