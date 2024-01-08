#include "drawable.cpp"
#pragma once
//curiosity
class Player:public Drawable
{
	int jheight=0;
	bool jump_active=false;
	bool up=true;
	public:
		Player()
		{
			setsprite("PFM");
			setpos(9,6);
			setheight();
		}
		void jump_activate()
		{
			jump_active=true;
		}
		bool is_jump_active()
		{
			if(jump_active)
			{
				return true;
			}
			return false;
		}
		void jump(WINDOW *win)
		{
			if(!jump_active)
			{
				return;
			}
			else
			{
				if(up)
				{
					
					if(jheight>0)
					{
						move_up(win,1);
						jheight++;
					}
					else
					{
						move_up(win,2);
						jheight+=2;
					}
					
				}
				else if(!up)
				{
					if(jheight>2)
					{
						move_down(win,1);
						jheight--;
					}
					else
					{
						move_down(win,2);
						jheight-=2;
					}
				};
				if(jheight == 6 and up)
				{
					up=false;
				};
				if(jheight==0 and !up)
				{
					jump_active=false;
					up=true;
					return;
				};
				
			}
		}
};