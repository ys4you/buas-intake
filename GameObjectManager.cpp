#include "precomp.h"

#include "GameObjectManager.h"
#include "GameObject.h"

int GameObjectManager::nextId = 0; // Initialize static nextId
std::map<int, GameObject*> GameObjectManager::gameObjects; 

GameObjectManager& GameObjectManager::Get() {
    static GameObjectManager instance;
    return instance;
}

void GameObjectManager::RegisterGameObject(GameObject* newGameObj) {
    if (!newGameObj) return; // Ensure it's a valid pointer

    int id = nextId++; // Assign a new ID
    newGameObj->SetId(id); 

    gameObjects[id] = newGameObj; // Store a raw pointer

    // Log message
    std::string logMessage = "GameObject Created: " + newGameObj->GetName() + " (ID: " + std::to_string(id) + ")\n";

#ifdef _DEBUG
    OutputDebugStringA(logMessage.c_str()); // Log to the Windows debugger
#endif
}

GameObject* GameObjectManager::GetGameObject(int id)
{
    auto it = gameObjects.find(id);
    return (it != gameObjects.end()) ? it->second : nullptr;
}

void GameObjectManager::RemoveGameObject(int id)
{
    auto it = gameObjects.find(id);
    if (it != gameObjects.end()) {
        std::cout << "Removing GameObject with ID: " << id << std::endl;
        gameObjects.erase(it);
    }
    else {
        std::cout << "Can not delete GameObject with ID: " << id << " not found!" << std::endl;
    }
}


void GameObjectManager::UpdateAllObjects(float deltaTime)
{
    for (auto& [id, gameObj] : gameObjects)
    {
        if (!gameObj)
        {
            std::cerr << "Warning: GameObject with ID " << id << " is nullptr!\n";
            continue;
        }
        else
        {
            //std::cout << "updating now: " << gameObj->GetName() << "with pointer: " << gameObj << std::endl;
            gameObj->Update(deltaTime);  // Safe to call Update()
        }
    }
}

void GameObjectManager::Deconstruct()
{
    for (auto& pair : gameObjects) 
    {
        delete pair.second; // Deletes each GameObject
    }
    gameObjects.clear(); // Clears the map
}