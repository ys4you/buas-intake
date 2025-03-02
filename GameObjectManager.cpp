#include "precomp.h"

#include "GameObjectManager.h"
#include "GameObject.h"

int GameObjectManager::nextId = 0; // Initialize static nextId
std::map<int, GameObject*> GameObjectManager::gameObjects; // Changed to std::map

GameObjectManager& GameObjectManager::Get() {
    static GameObjectManager instance;
    return instance;
}

void GameObjectManager::RegisterGameObject(GameObject* newGameObj) {
    if (!newGameObj) return; // Ensure it's a valid pointer

    int id = nextId++; // Assign a new ID
    newGameObj->SetId(id); // Assign the ID

    gameObjects[id] = newGameObj; // Store a raw pointer

    // Log message
    std::string logMessage = "GameObject Created: " + newGameObj->GetName() + " (ID: " + std::to_string(id) + ")\n";

#ifdef _DEBUG
    OutputDebugStringA(logMessage.c_str()); // Log to the Windows debugger
#endif

    std::cout << logMessage; // Log to console as well
}

GameObject* GameObjectManager::GetGameObject(int id) {
    auto it = gameObjects.find(id);
    return (it != gameObjects.end()) ? it->second : nullptr;
}

void GameObjectManager::RemoveGameObject(int id) {
    gameObjects.erase(id);
}

void GameObjectManager::UpdateAllObjects(float deltaTime)
{
    for (auto& [id, gameObj] : gameObjects)
    {
        if (!gameObj)  // Check if the pointer is valid
        {
            std::cerr << "Warning: GameObject with ID " << id << " is nullptr!\n";
            continue;
        }
        else
        {
            std::cout << "updating now: " << gameObj->GetName() << std::endl;
            gameObj->Update(deltaTime);  // Safe to call Update()
        }
    }
}

void GameObjectManager::Deconstruct() {
    for (auto& pair : gameObjects) {
        delete pair.second; // Deletes each GameObject
    }
    gameObjects.clear(); // Clears the map
}