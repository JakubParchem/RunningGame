#include<ncursesw/ncurses.h>
#include "Player.cpp"
#include "Cacti.cpp"
class Game
{
	Player player;
	Cactus cactus;
	int height,width,starty,startx;
	WINDOW *win;
	public:
		int score=0;
		int highscore=0;
		void start()
		{
			score=0;
			cactus.setpos(10,66);
			window_setup();
			int i=0;
			bool lost=false;
			while(!lost)
			{
				i=getch();
				if(i=='w' or i==' ' or i==KEY_UP)
				{
					player.jump_activate();
				}
				player.jump(win);
				cactus.cmove(win);
				collision(lost);
				print_score();
				score++;
			}
			high_score();
			clear();
			delwin(win);
			endwin();
		}
		void draw_ground()
		{
			wmove(win,12,1);
			for(int i=1;i<width-1;i++)
			{
				wprintw(win,"_");
			}
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
		void high_score()
		{
			if(highscore<score/4)
			{
				highscore=score/4;
			}
		}
		void print_score()
		{
			mvwprintw(win,1,39,"Highscore: %i  Score: %i",highscore,(score/4));
			wrefresh(win);
		}
		void window_setup()
		{
			initscr();
			keypad(stdscr, TRUE);
			curs_set(0);
			noecho();
			timeout(28);
			height = 15;
			width = 70;
			get_middle(stdscr,starty,startx,height,width);
			win =newwin(height,width,starty,startx);
			refresh();
			box(win,0,0);
			wrefresh(win);
			draw_ground();
			player.prin(win);
			cactus.prin(win);
		}
		void collision(bool &lost)
		{
			if(player.posx==cactus.posx and player.posy>=7)
				{
					lost=true;
				}
		}
	
};