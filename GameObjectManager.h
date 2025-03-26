#pragma once

#include <map>
#include <string>

class GameObject;

/// @brief Manages all GameObjects in the game.
class GameObjectManager {
public:
    /// @brief Gets the singleton instance of the GameObjectManager.
    /// @return Reference to the GameObjectManager instance.
    static GameObjectManager& Get();

    /// @brief Registers a new GameObject in the manager.
    /// @param newGameObj Pointer to the GameObject to register.
    void RegisterGameObject(GameObject* newGameObj);

    /// @brief Retrieves a GameObject by its unique ID.
    /// @param id The unique ID of the GameObject.
    /// @return Pointer to the GameObject, or nullptr if not found.
    GameObject* GetGameObject(int id);

    /// @brief Retrieves a GameObject by its name.
    /// @param name The name of the GameObject.
    /// @return Pointer to the GameObject, or nullptr if not found.
    GameObject* GetGameObjectByName(const std::string& name);

    /// @brief Removes a GameObject from the manager using its ID.
    /// @param id The unique ID of the GameObject to remove.
    void RemoveGameObject(int id);

    /// @brief Updates all registered GameObjects.
    /// @param deltaTime The time elapsed since the last update.
    void UpdateAllObjects(float deltaTime);

private:
    GameObjectManager();
    ~GameObjectManager();

    int nextId;
    std::map<int, GameObject*> gameObjects;

    GameObjectManager(const GameObjectManager&) = delete;
    GameObjectManager& operator=(const GameObjectManager&) = delete;
};
