#pragma once


#include <glm/glm.hpp>

struct AABB {
    glm::vec2 min; // Bottom-left corner
    glm::vec2 max; // Top-right corner 

    AABB(glm::vec2 min, glm::vec2 max) : min(min), max(max) {}
};

//source: https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/ I had done this before in my panic20 game
class CollisionHandler {
public:
    bool checkAABBCollision(const AABB& a, const AABB& b) {
        return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
            (a.min.y <= b.max.y && a.max.y >= b.min.y);
    }
};

