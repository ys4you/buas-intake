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


    GameObject(Surface* screen, const glm::vec2& pos = { 0, 0 }, int frames = 1, const glm::vec2& objSize = { 1, 1 }, std::string objPath = nullptr, const std::string& objName = "newGameObj", Collider objCollider = Collider())
        : screen(screen), position(pos), size(objSize), file_(objPath),  name_(objName), collider(objCollider), Id(-1), isDeleted_(false), frames_(frames)
    {
        Init();
    }

    virtual void Init()
    {
        GameObjectManager::Get().RegisterGameObject(this);



        if (collider.type == ColliderType::AABB)
            collider.SetAABB(AABB(position, position + size));

        if (!file_.empty())
            sprite_ = new Sprite(new Surface(file_.c_str()), frames_);
    }

    glm::vec2 GetPosition() const { return position; }
    void SetPosition(const glm::vec2& newPos)
    {
        position = newPos;
        if (collider.type == ColliderType::AABB)
        {
            collider.SetAABB(AABB(position, position + size));
        }
    }

    glm::vec2 GetSize() const { return  size; }

    int GetId() const { return Id; }
    void SetId(int newId) { Id = newId; }
    void SetFrameCount(int frameC)
    {
	    frameCount_ = frameC;
        sprite_ = new Sprite(new Surface(file_.c_str()), frameCount_);
    }
    Collider GetCollider() const { return collider; }
    std::string GetName() const { return name_;  }

    void MarkForDeletion()
    {
        isDeleted_ = true;
    }

    bool ShouldBeRemoved() const
    {
        return isDeleted_;
    }



    virtual void Update(float deltaTime)
    {
        // Default behavior, override in derived classes if needed

        if (collider.type == ColliderType::AABB)
        {
            collider.SetAABB(AABB(position, position + size));
#ifdef _DEBUG
            uint color = 0xFF0000; // Red color
            screen->Box(collider.aabb.min.x, collider.aabb.min.y,
                collider.aabb.max.x, collider.aabb.max.y, color);
#endif
        }

        Render();
    }

    virtual void Render()
    {
        if (file_.empty())
        {
            std::cout << "ERROR: Object: " << name_ << " (" << Id << ") Does not have a surface that can be rendered." << std::endl;
            return;
        }

        // Correct the frame update
        if (frames_ > 1)
        {
            sprite_->SetFrame(frameCount_); 
            if (++frameCount_ >= frames_) frameCount_ = 0; 
            std::cout << "Frame count of " + name_ + ": " << frameCount_ << "\n";
        }

        sprite_->Draw(screen, position.x, position.y);
    }


    bool CheckCollision(const GameObject& other) const
    {
        return collider.CheckCollision(other.collider);
    }

    void KeepInsideBoundary(const Collider& boundary)
    {
        if (collider.type == ColliderType::AABB)
        {
            // std::cout << "Before Clamping: \n";
            // std::cout << "AABB Min: (" << collider.aabb.min.x << ", " << collider.aabb.min.y << "), Max: (" << collider.aabb.max.x << ", " << collider.aabb.max.y << ")\n";
            // std::cout << "Boundary Min: (" << boundary.aabb.min.x << ", " << boundary.aabb.min.y << "), Max: (" << boundary.aabb.max.x << ", " << boundary.aabb.max.y << ")\n";

            // Check if player's AABB is outside the box and clamp it
            if (collider.aabb.min.x < boundary.aabb.min.x)
            {
                float offset = boundary.aabb.min.x - collider.aabb.min.x;
                position.x += offset;  // Move the position to stay inside boundary
                collider.aabb.min.x += offset;
                collider.aabb.max.x += offset;

                std::cout << "Clamped on X (Left): " << offset << std::endl;
            }
            if (collider.aabb.max.x > boundary.aabb.max.x)
            {
                float offset = collider.aabb.max.x - boundary.aabb.max.x;
                position.x -= offset;  // Move the position to stay inside boundary
                collider.aabb.min.x -= offset;
                collider.aabb.max.x -= offset;

                std::cout << "Clamped on X (Right): " << offset << std::endl;
            }
            if (collider.aabb.min.y < boundary.aabb.min.y)
            {
                float offset = boundary.aabb.min.y - collider.aabb.min.y;
                position.y += offset;  // Move the position to stay inside boundary
                collider.aabb.min.y += offset;
                collider.aabb.max.y += offset;

                std::cout << "Clamped on Y (Top): " << offset << std::endl;
            }
            if (collider.aabb.max.y > boundary.aabb.max.y)
            {
                float offset = collider.aabb.max.y - boundary.aabb.max.y;
                position.y -= offset;  // Move the position to stay inside boundary
                collider.aabb.min.y -= offset;
                collider.aabb.max.y -= offset;

                std::cout << "Clamped on Y (Bottom): " << offset << std::endl;
            }

            // Debugging: print final AABB values after clamping
            // std::cout << "After Clamping: \n";
            // std::cout << "AABB Min: (" << collider.aabb.min.x << ", " << collider.aabb.min.y << "), Max: (" << collider.aabb.max.x << ", " << collider.aabb.max.y << ")\n";
        }
        else
        {
            std::cout << "Not an AABB\n";
        }
    }


protected:
    GameObject(Surface* screen, const glm::vec2& pos, int frames, const glm::vec2& objSize, std::string objSurface, const std::string& objName, int objId, Collider objCollider)
        : screen(screen), position(pos), size(objSize), file_(objSurface), name_(objName), collider(objCollider), Id(objId), isDeleted_(false), frames_(frames)
    {
    }

    Surface* screen;

    glm::vec2 position;
    glm::vec2 size;
    Collider collider;
    int Id;
    std::string name_;

    std::string file_;
    Sprite* sprite_;
    bool isDeleted_;
    int frames_;
    int frameCount_;
};