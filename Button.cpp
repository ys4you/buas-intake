#include "precomp.h"
#include "Button.h"

void Button::Update(float deltaTime)
{
	//GameObject::Update(deltaTime); // calls the base Update function. Not going to Use since we want to handle Rendering differently.
}

void Button::IsActive(bool isActive)
{
    RenderButton(isActive ? buttonActivePath : buttonInactivePath);
}

void Button::RenderButton(std::string file)
{
    if (file.empty())
    {
        std::cout << "ERROR: Object: " << name_ << " (" << Id << ") Does not have a surface that can be rendered." << std::endl;
        return;
    }
    Sprite objSprite(new Surface(file.c_str()), 1);

    objSprite.Draw(screen, position.x, position.y);
}