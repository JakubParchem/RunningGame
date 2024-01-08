#include<ncursesw/ncurses.h>
#include "Player.cpp"
#include "Cacti.cpp"
class Game
{
	Player player;
	Cactus cactus[2];
	int height,width,starty,startx;
	int speed;
	int space=100;
	WINDOW *win;
	public:
		int score=0;
		int highscore=0;
		void start()
		{
			score=0;
			speed=1;
			space=100;
			int next_space=0;
			window_setup();
			int i=0;
			bool lost=false;
			while(!lost)
			{
				printspeed();
				i=getch();
				if(i=='w' or i==' ' or i==KEY_UP)
				{
					player.jump_activate();
				}
				player.jump(win);
				if(cactus[0].posx-1==1)
				{
					cactus[1].rand_space(next_space);
				}
				if(!cactus[1].active)
				{
					if(cactus[0].posx<=40)
					{
						space=next_space;
						cactus[1].active=true;
					}
				}
				cactus[0].cmove(win,speed);
				if(space<=0 and cactus[1].active)
				{
					cactus[1].cmove(win,speed,true);
				}
				else
				{
					space--;
				}
				for(auto i:cactus)
				{
					collision(lost,i);
				}
				print_score();
				score++;
				speedup();
			}
			high_score();
			clear();
			cactus[0].rand_sprite();
			cactus[1].rand_sprite(highscore);
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
			cactus[0].active=true;
			cactus[1].active=false;
			for(auto i:cactus)
			{
				i.clean(win);
			}
			player.clean(win);
			cactus[0].rand_sprite();
			cactus[1].rand_sprite(highscore);
			draw_ground();
			player.prin(win);
			cactus[0].prin(win);
		}
		void collision(bool &lost,Cactus &cactus)
		{
			if(player.posx==cactus.posx and player.posy>=9-cactus.height)
				{
					lost=true;
				}
		}
		void speedup()
		{
			if(speed==1 and (score>=400 and (cactus[0].posx-player.posx)%2==0))
				{
					speed=2;
				}
				if(speed==2 and (score>=1250 and (cactus[0].posx-player.posx)%3==0))
				{
					speed=3;
				}
				if(speed==3 and (score>=4000 and (cactus[0].posx-player.posx)%4==0))
				{
					speed=4;
				}
		}
		void printspeed()
		{
			mvwprintw(win,1,1,"                    ");
			mvwprintw(win,1,1,"speed : %i",space);
			wrefresh(win);
		}
	
};