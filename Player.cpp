#include "precomp.h"
#include "Player.h"

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	std::cout << file_ << std::endl;
}

