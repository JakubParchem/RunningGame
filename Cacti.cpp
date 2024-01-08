#include "drawable.cpp"
#include <cstdlib>
#include <ctime>
#pragma once
class Cactus: public Drawable
{
	int speed;
	public:
		bool active;
		Cactus()
		{
			rand_sprite();
		}
		void cmove(WINDOW *win,int speed=1,bool once=false)
		{
			if(posx==1)
			{
				clean(win);
				rand_sprite();
				if(!once)
				{
					prin(win);
				};
				if(once)
				{
					active=false;
				}
			}
			else
			{
				move_left(win,speed);
			}
		}
		void rand_sprite(int add=0)
		{
			srand (time(NULL)+add);
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
		void rand_space(int &space)
		{
			if(rand()%10<=5)
			{
				space=24;
			}
			else
			{
				space=36;
			}
		}
};