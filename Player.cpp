#include "drawable.cpp"
#pragma once
class Player
{
	Drawable character;
	public:
		Player()
		{
			character.setsprite("PFM");
			character.setpos(9,6);
		}
		void draw(WINDOW *win)
		{
			character.prin(win);
		}
};