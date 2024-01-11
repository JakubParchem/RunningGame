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
			rocktab[0].rmove(win,speed);
			rocktab[1].rmove(win,speed);
			rocktab[2].rmove(win,speed);
			rocktab[3].rmove(win,speed);
			rocktab[4].rmove(win,speed);
		}
		void rsinitialpos()
		{
			rocktab[0].initialpos();
			rocktab[1].initialpos();
			rocktab[2].initialpos();
			rocktab[3].initialpos();
			rocktab[4].initialpos();
		}
		void rclean(WINDOW *win)
		{
			rocktab[0].clean(win);
			rocktab[1].clean(win);
			rocktab[2].clean(win);
			rocktab[3].clean(win);
			rocktab[4].clean(win);
		}
};