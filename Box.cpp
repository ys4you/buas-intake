#include "precomp.h"
#include "Box.h"

void Box::Update(float deltaTime)
{
	Box::Render();
}


void Box::Render()
{
    uint color = 0x00FF00; // Green color

    for (int i = 0; i < 5; i++) 
    {
        screen->Box(
            position.x - i, position.y - i,
            position.x + size.x + i, position.y + size.y + i,
            color
        );
    }
}