#pragma once


namespace Tmpl8
{
	class Player
	{
	public:
		static Sprite playerSprite;
		int xPos;
		int yPos;

		Player(Sprite pSprite, int pXPos, int pYpos)
		{
			playerSprite = pSprite;
			xPos = pXPos;
			yPos = pYpos;
		}
	};
}


