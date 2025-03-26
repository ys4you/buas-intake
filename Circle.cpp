#include "precomp.h"
#include "Circle.h"

Circle::~Circle()
{
	for (const auto projectile : projectiles)
	{
		if (projectile != nullptr)
		{
            projectile->MarkForDeletion();
		}
	}
}

void Circle::SpawnCircle()
{
    std::cout << "spawning circle\n";
    projectiles.reserve(projectilesAmount);
    for (int i = 0; i < projectilesAmount; i++)
    {
        float angle = (2.0f * PI / projectilesAmount) * i + (3.0f * PI / 2.0f);
        glm::vec2 pos = {
            center.x + radius * cos(angle),
            center.y + radius * sin(angle)
        };
        SphereProjectile* s = new SphereProjectile(screen, pos, projSize, angle);

        s->shouldRender = false;
        projectiles.push_back(s);
    }
}

void Circle::SpiralCircle(float deltaTime)
{
    projTimer += deltaTime / 1000.f; 

    const float projInterval = 0.2f;

    for (int i = 0; i < projectiles.size(); ++i)
    {


        if (projTimer >= i * projInterval)
        {
            projectiles[i]->shouldRender = true;
            MoveProjToCenter(projectiles[i], deltaTime);
        }
    }

    if (projTimer >= 2.5f)
    {
        spiralIsDone = true;
    }

    if(projTimer >= 4.f)
    {
        for (int i = 0; i < projectiles.size(); ++i)
            projectiles[i]->shouldRender = false;
    }
}


void Circle::MoveProjToCenter(SphereProjectile* proj, float deltaTime)
{
    if (proj == nullptr)
        return;

    const float moveDistance = 0.4f * deltaTime;
    const float negativeMoveDistance = -0.008f * deltaTime;


    glm::vec2 currentPos = proj->GetPosition();

    if (proj->initialDirection == glm::vec2(0.f, 0.f)) {
        // Calculate initial direction only once
        proj->initialDirection = glm::normalize(center - currentPos);
    }
    glm::vec2 newPos;

    if (proj->timer <= 1.f)
        newPos = { currentPos.x + proj->initialDirection.x * negativeMoveDistance ,currentPos.y + proj->initialDirection.y * negativeMoveDistance };
    else
        newPos = { currentPos.x + proj->initialDirection.x * moveDistance ,currentPos.y + proj->initialDirection.y * moveDistance };

    proj->SetPosition(newPos);

    const float deltaTimeInSeconds = deltaTime / 1000.f;
    proj->timer += deltaTimeInSeconds;
}
