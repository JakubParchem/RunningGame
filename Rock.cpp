#include "drawable.cpp"
class Rock:public Drawable
{
	public:
		int x,y=13;
		Rock()
		{
			setsprite(".");
		}
		void rsetpos(int x)
		{
			this->x=x;
			setpos(y,x);
		}
		void rmove(WINDOW *win,int speed)
		{
			if(posx==1)
			{
				move_right(win,67);
			}
			else
			{
				move_left(win,speed);
			}
		}
		void initialpos()
		{
			setpos(y,x);	
		}
};
class Rocks
{
	Rock rocktab[5];
	public:
		Rocks()
		{
			rocktab[0].rsetpos(10);
			rocktab[1].rsetpos(23);
			rocktab[2].rsetpos(31);
			rocktab[3].rsetpos(49);
			rocktab[4].rsetpos(60);
		}
		void rsmove(WINDOW *win,int speed)
		{
			for(auto i:rocktab)
			{
				i.rmove(win,speed);
			}
		}
		void rsinitialpos()
		{
			for(auto i:rocktab)
			{
				i.initialpos();
			}
		}
		void rclean(WINDOW *win)
		{
			for(auto i:rocktab)
			{
				i.clean(win);
			}
		}
};