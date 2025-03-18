#include "precomp.h"
#include "DiamondProjectile.h"

void DiamondProjectile::Update(float deltaTime)
{
	Projectile::Update(deltaTime);

	SetPosition({ position.x, position.y + speed * deltaTime });
	//std::cout << "position = x: " << position.x << " y: " << position.y << std::endl;

	if (!shouldRender)
	{
		MarkForDeletion();
	}

}