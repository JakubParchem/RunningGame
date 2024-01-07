#include<ncursesw/ncurses.h>
#include<iostream>
#include"game_window.cpp"
#include"menu_window.cpp"
int main()
{
	Menu menu;
	Game game;
	while(true)
	{
		menu.start(game.highscore,game.score);
		if(menu.is_quiting())
		{
			return 0;
		}
		game.start();
	}
	
}