#pragma once

#include <iostream>
#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include "Collider.h"
#include "GameObjectManager.h"
#include "sprite.h"

//TODO: Make logic to cpp source file

class GameObject
{
public:
    virtual ~GameObject() = default;

    /// @brief Constructs a GameObject with specified parameters.
	/// @param screen The surface where the object will be drawn.
	/// @param pos The initial position of the object.
	/// @param frames The number of animation frames.
	/// @param objSize The size of the object.
	/// @param objPath The file path of the object's sprite.
	/// @param objName The name of the object.
	/// @param objCollider The collider associated with the object.
    GameObject(Surface* screen, const glm::vec2& pos = { 0, 0 }, int frames = 1, const glm::vec2& objSize = { 1, 1 }, std::string objPath = nullptr, const std::string& objName = "newGameObj", Collider objCollider = Collider())
        : screen(screen), position(pos), size(objSize), file_(objPath),  name_(objName), collider(objCollider), Id(-1), isDeleted_(false), frames_(frames)
    {
        Init();
    }

    /// @brief Initializes the GameObject, registering it and setting up its collider and sprite.
    virtual void Init()
    {
        GameObjectManager::Get().RegisterGameObject(this);



        if (collider.type == ColliderType::AABB)
            collider.SetAABB(AABB(position, position + size));

        if (!file_.empty())
            sprite_ = new Sprite(new Surface(file_.c_str()), frames_);
    }

    /// @brief Gets the current position of the GameObject.
	/// @return The position as a glm::vec2.
    glm::vec2 GetPosition() const { return position; }

    /// @brief Sets a new position for the GameObject and updates the collider.
	/// @param newPos The new position to set.
    void SetPosition(const glm::vec2& newPos)
    {
        position = newPos;
        if (collider.type == ColliderType::AABB)
        {
            collider.SetAABB(AABB(position, position + size));
        }
    }

    /// @brief Gets the size of the GameObject.
	/// @return The size as a glm::vec2.
    glm::vec2 GetSize() const { return  size; }

    /// @brief Gets the unique ID of the GameObject.
    /// @return The object's ID.
    int GetId() const { return Id; }

    /// @brief Sets the ID of the GameObject.
    /// @param newId The new ID to assign.
    void SetId(int newId) { Id = newId; }

    /// @brief Sets the number of animation frames and updates the sprite accordingly.
    /// @param frameC The number of frames.
    void SetFrameCount(int frameC)
    {
	    frameCount_ = frameC;
        sprite_ = new Sprite(new Surface(file_.c_str()), frameCount_);
    }

    /// @brief Gets the collider associated with the GameObject.
    /// @return The Collider object.
    Collider GetCollider() const { return collider; }

    /// @brief Gets the name of the GameObject.
    /// @return The name as a string.
    std::string GetName() const { return name_;  }

    /// @brief Marks the GameObject for deletion.
    void MarkForDeletion(){ isDeleted_ = true; }

    /// @brief Checks if the GameObject should be removed.
    /// @return True if the object is marked for deletion, false otherwise.
    bool ShouldBeRemoved() const
    {
        return isDeleted_;
    }


    /// @brief Updates the GameObject's state.
    /// @param deltaTime The time elapsed since the last update.
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

    /// @brief Renders the GameObject on the screen.
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
            //std::cout << "Frame count of " + name_ + ": " << frameCount_ << "\n";
        }

        sprite_->Draw(screen, position.x, position.y);
    }


    /// @brief Checks if this GameObject collides with another GameObject.
    /// @param other The other GameObject to check against.
    /// @return True if a collision occurs, false otherwise.
    bool CheckCollision(const GameObject& other) const
    {
        return collider.CheckCollision(other.collider);
    }

    /// @brief Ensures the GameObject stays within a specified boundary.
    /// @param boundary The collider defining the boundary.
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
    /// @brief Protected constructor for derived classes.
    /// @param screen The surface where the object will be drawn.
    /// @param pos The initial position of the object.
    /// @param frames The number of animation frames.
    /// @param objSize The size of the object.
    /// @param objSurface The file path of the object's sprite.
    /// @param objName The name of the object.
    /// @param objId The unique ID of the object.
    /// @param objCollider The collider associated with the object.
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
    int frameCount_ = 0;
};