#include "precomp.h"
#include "ActionMenu.h"

void ActionMenu::Render()
{
	uint color = 0xFF00FF; // Purple color (Red + Blue)

	screen->Box(position.x, position.y, position.x + size.x, position.y + size.y, color);
}
