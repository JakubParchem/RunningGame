#include "drawable.cpp"
#pragma once
//curiosity
class Player:public Drawable
{
	int height=0;
	bool jump_active=false;
	bool up=true;
	public:
		Player()
		{
			setsprite("PFM");
			setpos(9,6);
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
					move_up(win,1);
					height++;
				}
				else if(!up)
				{
					move_down(win,1);
					height--;
				};
				if(height == 5 and up)
				{
					up=false;
				};
				if(height==0 and !up)
				{
					jump_active=false;
					up=true;
					return;
				};
				
			}
		}
};