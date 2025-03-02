#pragma once

#include <iostream>
#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include "Collider.h"
#include "GameObjectManager.h"
#include "sprite.h"

class GameObject
{
public:
    virtual ~GameObject() = default;

    GameObject(Surface* screen, const glm::vec2& pos = { 0, 0 }, const glm::vec2& objSize = { 1, 1 }, std::string objPath = nullptr, const std::string& objName = "newGameObj")
        : screen(screen), position(pos), size(objSize), file_(objPath), name_(objName), Id(-1)
    {
        Init();
    }

    glm::vec2 GetPosition() const { return position; }
    void SetPosition(const glm::vec2& newPos) { position = newPos; }

    int GetId() const { return Id; }
    void SetId(int newId) { Id = newId; }

    std::string GetName() const { return name_;  }

    virtual void Init()
    {
        GameObjectManager::Get().RegisterGameObject(this);
    }

    virtual void Update(float deltaTime)
    {
        // Default behavior, override in derived classes if needed
        Render();
    }

    virtual void Render()
    {
        //std::cout << "Rendering Object: " << name_ << " (" << Id << ")." << std::endl;

        if (file_.empty())
        {
            std::cout << "ERROR: Object: " << name_ << " (" << Id << ") Does not have a surface that can be rendered." << std::endl;
            return;
        }
        Sprite objSprite(new Surface(file_.c_str()), 1);

        objSprite.Draw(screen, position.x, position.y);
    }

    bool CheckCollision(const GameObject& other) const
    {
        return collider.CheckCollision(other.collider);
    }

protected:
    GameObject(Surface* screen, const glm::vec2& pos, const glm::vec2& objSize, std::string objSurface, const std::string& objName, int objId)
        : screen(screen), position(pos), size(objSize), file_(objSurface), name_(objName), Id(objId)
    {
    }

    Surface* screen;

    glm::vec2 position;
    glm::vec2 size;
    Collider collider;
    int Id;
    std::string name_;

    std::string file_;
};