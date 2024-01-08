#include "drawable.cpp"
#include <cstdlib>
#include <ctime>
#pragma once
class Cactus: public Drawable
{
	int speed;
	public:
		Cactus()
		{
			rand_sprite();
		}
		void cmove(WINDOW *win,int speed=1)
		{
			if(posx==1)
			{
				clean(win);
				rand_sprite();
				prin(win);
			}
			else
			{
				move_left(win,speed);
			}
		}
		void rand_sprite()
		{
			srand (time(NULL));
			if(rand()%10<=5)
			{
				setsprite("##");
			}
			else
			{
				setsprite("###");
			}
			setheight();
			setpos(12-height,66);
		}
};