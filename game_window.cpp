#pragma once
	#include<ncursesw/ncurses.h>
	#include "Player.cpp"
class Game
{
	Player player;
	
	public:
		void start()
		{
			initscr();
			noecho();
			int height,width,starty,startx;
			height = 15;
			width = 70;
			starty=startx=5;
			WINDOW *win =newwin(height,width,starty,startx);
			refresh();
			box(win,0,0);
			wrefresh(win);
			draw_ground(win);
			player.draw(win);
			getch();
			clear();
			endwin();
		}
		void draw_ground(WINDOW *win)
		{
			wmove(win,12,1);
			for(int i=1;i<69;i++)
			{
				wprintw(win,"_");
			}
			wrefresh(win);
		}
	
};