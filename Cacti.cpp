#include "drawable.cpp"
#pragma once
class Cactus: public Drawable
{
	int speed;
	public:
		Cactus()
		{
			setpos(10,66);
			setsprite("##");
		}
		cmove(WINDOW *win,int speed=1)
		{
			if(posx==1)
			{
				move_right(win,64);
			}
			else
			{
				move_left(win,speed);
			}
		}
};