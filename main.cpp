#include<ncursesw/ncurses.h>
#include<iostream>
#include "Player.cpp"
#include"game_window.cpp"
int main()
{
	Player dino;
	initscr();
	noecho();
	int height,width,starty,startx;
	height = 15;
	width = 70;
	starty=startx=10;
	WINDOW *win =newwin(height,width,starty,startx);
	refresh();
	box(win,0,0);
	wrefresh(win);
	dino.draw(win);
	getch();
	endwin();
	
	
}