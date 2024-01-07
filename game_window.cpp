#include<ncursesw/ncurses.h>
#include "Player.cpp"
class Game
{
	Player player;
	int height,width,starty,startx;
	int score=0;
	int highscore=0;
	WINDOW *win;
	public:
		void start()
		{
			initscr();
			keypad(stdscr, TRUE);
			noecho();
			curs_set(0);
			timeout(32);
			height = 15;
			width = 70;
			get_middle(stdscr,starty,startx,height,width);
			win =newwin(height,width,starty,startx);
			refresh();
			box(win,0,0);
			wrefresh(win);
			draw_ground();
			player.prin(win);
			int i=0;
			while(i!='q')
			{
				i=getch();
				if(i=='w' or i==' ' or i==KEY_UP)
				{
					player.jump_activate();
				}
				player.jump(win);
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
			if(highscore<score/2)
			{
				highscore=score/2;
			}
			score=0;
		}
		void print_score()
		{
			mvwprintw(win,1,39,"Highscore: %i  Score: %i",highscore,(score/2));
			wrefresh(win);
		}
	
};