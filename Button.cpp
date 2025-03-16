#include "precomp.h"
#include "Button.h"

Button::~Button()
{
	GameObject::~GameObject();
}

void Button::Update(float deltaTime)
{
	//GameObject::Update(deltaTime); // calls the base Update function. Not going to Use since we want to handle Rendering differently.
}

void Button::IsActive(bool isActive)
{
    RenderButton(isActive ? buttonActive: buttonInactive);
}

void Button::RenderButton(Sprite* sprite)
{
	if (!sprite)
		return;

    sprite->Draw(screen, position.x, position.y);
}