#include "precomp.h"
#include "DummyAttackOne.h"

DummyAttackOne::DummyAttackOne(Surface* screen, int amount, float duration) :
BaseAttack(screen, duration, 0),
projectilesAmount(amount)
{
	projectiles.reserve(projectilesAmount);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(SCRHEIGHT / 3 - 125, SCRHEIGHT / 3 + 125 - 32);

	for (int i = 0; i < projectilesAmount; ++i)
	{
		int randomY = distrib(gen);
		SphereProjectile* projectile = new SphereProjectile(screen,{ SCRWIDTH + 64, randomY});
		projectiles.push_back(projectile); 

        std::cout << "Projectile " << i << " spawned at: (" << (SCRWIDTH + 64) << ", " << randomY << ")" << std::endl;
	}
}

void DummyAttackOne::Update(float deltaTime)
{
	if (isDestroying)
        return;

    if(!isAttacking)
        return;

    const float deltaTimeInSeconds = deltaTime / 1000.f;


	const float intrVal = attackTime / projectilesAmount;
    //float interval = 0.5f; //test

    for (int i = 0; i < projectilesAmount; ++i)
    {
        if (timer >= i * intrVal) 
        {
            glm::vec2 newPos = projectiles[i]->GetPosition();

            if (newPos.x <= -32)
            {
                continue;
            }
            newPos.x -= projectiles[i]->speed * deltaTimeInSeconds;
            projectiles[i]->SetPosition(newPos); 
            //std::cout << "i: " << i << " sphere(" << projectiles[i]->GetId() << ") should be moving to x: " << newPos.x << " y: " << newPos.y << std::endl;
        }
    }

    if (timer >= attackTime)
    {
        ResetAttack();
    }
    else
    {
        timer += deltaTimeInSeconds;
    }
}

void DummyAttackOne::ResetAttack()
{
    BaseAttack::ResetAttack();
    if (isDestroying)
        return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(SCRHEIGHT / 3 - 125, SCRHEIGHT / 3 + 125 - 32);


    for (auto i = 0; i < projectilesAmount; i++)
    {
        int randomY = dist(gen);
        glm::vec2 currentPos = projectiles[i]->GetPosition();
        projectiles[i]->SetPosition({ SCRWIDTH + 64, randomY });
    }
}

DummyAttackOne::~DummyAttackOne()
{
    isDestroying = true;
    std::cout << "Deconstructing DummyAttackOne and removing projectiles\n";

    for (int i = 0; i < projectiles.size(); ++i)
    {
        if (projectiles[i] != nullptr) 
        {
            projectiles[i]->MarkForDeletion();
        }
    }

    projectiles.clear();
}