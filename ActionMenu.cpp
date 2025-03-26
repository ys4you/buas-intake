#include "precomp.h"
#include "ActionMenu.h"



int currentIndex = 0;
void ActionMenu::Render()
{
	uint color = 0xFF00FF; // Purple color (Red + Blue)

	uint color2 = 0x00FFFF; // Cyan color (Green + Blue)

	screen->Box(position.x, position.y, position.x + size.x, position.y + size.y, color);

	if (isMenuActive)
	{
		screen->Box(characterMenuPos.x1_, characterMenuPos.y1_, characterMenuPos.x2_, characterMenuPos.y2_, color2);

		//buttons

		for (int i = 0; i < buttons.size(); i++) 
		{
			buttons[i]->SetRenderState(true);

			if (i == ButtonIndexState) 
			{
				buttons[i]->IsActive(true);
			}
			else 
			{
				buttons[i]->IsActive(false);
			}
		}

	}
	else
	{
		for (int i = 0; i < buttons.size(); i++) 
			buttons[i]->SetRenderState(false);
	}
}


void ActionMenu::Fight()
{
	if (levelOfDeepness == 1)
	{
		screen->PrintScaled((std::string("- ") + enemy_->GetName()).c_str(), position.x + 50, position.y + 20,2,2, 0xFFFFFF);
	}
	else if (levelOfDeepness == 2)
	{
		ResetMenu();
	}
}

void ActionMenu::Item()
{
	float spacingY = size.y / healingItems.size();  
	float spacingX = size.x / 2;  

	for (size_t i = 0; i < healingItems.size(); ++i)
	{
		float posX = position.x + (i % 2) * spacingX + 50;  
		float posY = position.y + (i / 2) * spacingY + 20;

		if (i == ItemIndexState)
		{
			screen->PrintScaled((std::string("- ") + healingItems[i]->itemName).c_str(), posX, posY, 2, 2, 0xFFFFFF);
		}
		else
		{
			screen->PrintScaled((std::string("- ") + healingItems[i]->itemName).c_str(), posX, posY, 2, 2, 0xD3D3D3);

		}

		if (levelOfDeepness == 2)
		{
			healingItems[i]->HealPlayer();
			healingItems.erase(healingItems.begin() + i);
			ItemIndexState = 0;
			ResetMenu();
		}

	}
}


void ActionMenu::Spare()
{
	if (levelOfDeepness == 1)
	{
		//screen->Print("- Spare", position.x + 50, position.y + 20, 0xFFFFFF);
		screen->PrintScaled("- Spare", position.x + 50, position.y + 20, 2, 2, 0xFFFFFF);
	}
	else if (levelOfDeepness == 2)
	{
		ResetMenu();
	}
}

void ActionMenu::Defend()
{
	if (levelOfDeepness == 1)
	{
		screen->PrintScaled("- Spare (At the moment. It does nothing)", position.x + 50, position.y + 20, 2,2, 0xA9A9A9);
	}
	else if (levelOfDeepness == 2)
	{
		ResetMenu();
	}
}

void ActionMenu::ResetMenu()
{
	levelOfDeepness = 0;
	ButtonIndexState = 0;
	isMenuActive = false;
	isDone = true;
}

void ActionMenu::SwitchActiveState(bool shouldBeActive)
{
	isMenuActive = shouldBeActive;
}

bool ActionMenu::DidAction() const { return isDone; }

void ActionMenu::resetAction(){	isDone = false; }

void ActionMenu::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (levelOfDeepness == 0)
		{
			if (!leftPressed)
			{
				ButtonIndexState--;
				leftPressed = true;
			}
		}
	}
	else
		leftPressed = false;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (levelOfDeepness == 0)
		{
			if (!rightPressed)
			{
				ButtonIndexState++;
				rightPressed = true;
			}
		}
	}
	else
	{
		rightPressed = false;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (levelOfDeepness == 1)
		{
			if (!leftPressed)
			{
				ItemIndexState--;
				leftPressed = true;
			}
		}
	}
	else
		leftPressed = false;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (levelOfDeepness == 1)
		{
			if (!rightPressed)
			{
				ItemIndexState++;
				rightPressed = true;
			}
		}
	}
	else
	{
		rightPressed = false;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (!enterPressed) 
		{
			levelOfDeepness++;
			enterPressed = true;
		}
	}
	else
	{
		enterPressed = false; 
	}

	if (GetAsyncKeyState(VK_BACK) & 0x8000)
	{
		if (!backspacePressed) 
		{
			backspacePressed = true;
			if (levelOfDeepness <= 0 )
				return;

				levelOfDeepness--;
		}
	}
	else
	{
		backspacePressed = false;
	}

	if (ButtonIndexState <= -1)
	{
		ButtonIndexState = buttons.size() - 1;
	}
	else if (ButtonIndexState >= buttons.size())
	{
		ButtonIndexState = 0;
	}

	if (ItemIndexState < 0)
	{
		ItemIndexState = 0; 
	}
	else if (ItemIndexState >= healingItems.size())
	{
		ItemIndexState = healingItems.size() - 1; 
	}

	if (levelOfDeepness > 0)
	{
		switch (ButtonIndexState)
		{
		case 0:
			Fight();
			break;
		case 1:
			ResetMenu(); //act
			break;
		case 2:
			Item();
			break;
		case 3:
			Spare();
			break;
		case 4:
			Defend();
			break;
		}
	}
}


