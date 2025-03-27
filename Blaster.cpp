#include "precomp.h"
#include "Blaster.h"
#include "common.h"


void Blaster::SpawnBlasterAtPlayer()
{
    glm::vec2 boxPos = box->GetPosition();
    glm::vec2 boxSize = box->GetSize();
    int spawnOffset = 25;
    glm::vec2 spawnPos = {};  // Position of the blaster

    switch (randomDir)
    {
    case 0: // Up (above the box, but at player's X)
        spawnPos = { playerPos.x, boxPos.y - spawnOffset - size.y };
        blastSize = { size.x, SCRHEIGHT - spawnPos.y };  // Blast goes down with the full screen height
        break;

    case 1: // Right (right of the box, but at player's Y)
        spawnPos = { boxPos.x + boxSize.x + spawnOffset, playerPos.y };
        blastSize = { 0 - spawnPos.x, size.y };  // Blast goes left with the full screen width
        break;

    case 2: // Down (below the box, but at player's X)
        spawnPos = { playerPos.x, boxPos.y + boxSize.y + spawnOffset };
        blastSize = { size.x - 2, 0 - spawnPos.y };  // Blast goes up with the full screen height
        break;

    case 3: // Left (left of the box, but at player's Y)
        spawnPos = { boxPos.x - spawnOffset - size.x, playerPos.y };
        blastSize = { SCRWIDTH - spawnPos.x, size.y };  // Blast goes right with the full screen width
        break;

    default:
        std::cout << "randomDir not initiated correctly. Not spawning Blaster\n";
        break;
    }

    // Set the position and size
    SetPosition(spawnPos);
}


Blaster::~Blaster()
{
    if(blast != nullptr)
    {
        blast->MarkForDeletion();
    }
}

void Blaster::Update(float deltaTime)
{
    GameObject::Update(deltaTime);

    if( SpawnCooldown >= 0)
    {
        SpawnCooldown -= deltaTime / 1000.f;
        return;
    }

    if(blastCooldown >= 0)
    {
		FireBlast();
        blastCooldown -= deltaTime / 1000.f;
        return;
    }
    else
    {
	    if (blast != nullptr)
	    {
            blast->MarkForDeletion();
            MarkForDeletion();
	    }
    }

}

void Blaster::FireBlast()
{
	if (blast == nullptr)
	{
        glm::vec2 pos = position;
        switch (randomDir)
        {
        case 0:
            pos = { position.x, position.y + size.y / 2 };
            break;

        case 1:
            pos = { position.x + size.x / 2, position.y};
            break;

        case 2:
            pos = { position.x, position.y + size.y / 2 };
            blastSize = { blastSize.x, blastSize.y - size.y / 2 };
            break;

        case 3:
            pos = { position.x + size.x / 2, position.y };
            break;

        default:
            break;
        }

		std::cout << "init Blast\n";
        blast = new Blast(screen, pos, blastSize);
	}
}

