#include <ncursesw/ncurses.h>
#include<iostream>
#pragma once
class Drawable
{
	protected:
		int height;
		std::string sprite;
	public:
		int posx=0;
		int posy=0;
		void setpos(int y,int x)
		{
			posx=x;
			posy=y;
		}
		void setsprite(std::string sprite)
		{
			this->sprite=sprite;
			height=sprite.size();
		}
		void prin(WINDOW *win)
		{
			int y=posy;
			int x=posx;
			for (int i=0;i<height;i++)
			{
			mvwprintw(win,y++,posx,"%c",sprite[i]);
			}
			wrefresh(win);
		}
		void clean(WINDOW *win)
		{
			int y=posy;
			for (int i=0;i<height;i++)
			{
			mvwprintw(win,y++,posx," ");
			}
			wrefresh(win);
		}
		void move_left(WINDOW *win,int step=4)
		{
			clean(win);
			if(posx-step>0)
			{	
				posx-=step;	
			}
			else
			{
				posx=1;
			}
			prin(win);
		}
		void move_right(WINDOW *win,int step=4)
		{
			int x;
			int y;
			getmaxyx(win,y,x);
			clean(win);
			if(posx+step<x)
			{	
				posx+=step;	
			}
			else
			{
				posx=x-1;
			}
			prin(win);
		}
		void move_up(WINDOW *win,int step=2)
		{
			clean(win);
			if(posx-step>0)
			{	
				posy-=step;	
			}
			else
			{
				posy=1;
			}
			prin(win);
		}
		void move_down(WINDOW *win,int step=2)
		{
			int x;
			int y;
			getmaxyx(win,y,x);
			clean(win);
			if(posy+step<y)
			{	
				posy+=step;	
			}
			else
			{
				posy=y-1;
			}
			prin(win);
		}
};