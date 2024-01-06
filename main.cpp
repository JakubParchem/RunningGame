#include<ncursesw/ncurses.h>
#include<iostream>
#include"game_window.cpp"
#include"menu_window.cpp"
int main()
{
	Menu menu;
	Game game;
	menu.start();
	game.start();
	
}