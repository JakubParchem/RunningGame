#include<ncursesw/ncurses.h>
#pragma once

class Menu
{
	bool first_time=true;
	
	public:
	void start()
	{
		initscr();
		noecho();
		int height,width,starty,startx;
		height = 20;
		width = 41;
		get_middle(stdscr,starty,startx,height,width);
		WINDOW *win =newwin(height,width,starty,startx);
		refresh();
		box(win,0,0);
		wrefresh(win);
		draw_title(win);
		getch();
		clear();
		endwin();
	}	
	void draw_title(WINDOW *win)
	{
		mvwprintw(win,1,1,"    __                            ___");
		mvwprintw(win,2,1,"   |__) |  | |\\  | |\\  | | |\\  | /   \\");
		mvwprintw(win,3,1,"   |\\   |  | | \\ | | \\ | | | \\ | |  __");
		mvwprintw(win,4,1,"   | \\  \\__/ |  \\| |  \\| | |  \\| \\___/");
		mvwprintw(win,5,1,"         ___    ___          ___");
		mvwprintw(win,6,1,"        /   \\  /   \\ |\\  /| |");
		mvwprintw(win,7,1,"        |  __  |---| | \\/ | |---");
		mvwprintw(win,8,1,"        \\___/  |   | |    | |___");
		wrefresh(win);
		
	}
	void get_middle(WINDOW *win, int &y, int &x,int h, int w)
		{
			getmaxyx(win,y,x);
			y/=2;
			x/=2;
			x-=(w/2);
			y-=(h/2);
		}
};