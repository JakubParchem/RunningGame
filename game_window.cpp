#include<ncursesw/ncurses.h>
#include "Player.cpp"
#include "Cacti.cpp"
class Game
{
	Player player;
	Cactus cactus[2];
	int height,width,starty,startx;
	int speed;
	int space;
	int delay;
	bool delay_active;
	bool lost;
	WINDOW *win;
	public:
		int score=0;
		int highscore=0;
		void start()
		{
			window_setup();
			int i=0;
			while(!lost)
			{
				printvar();
				speedup();
				if(delay_active)
				{
					delay--;
				}
				jumping(i);
				if(i=='q')
				{
					break;
				}
				cacti_moving(speed,space);
				for(auto i:cactus)
				{
					cactus_collision(lost,i);
				}
				print_score();
				score++;	
			}
			game_end();
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
			set_variables_value();
			window_initialisation();
			objects_setup();	
		}
		void cactus_collision(bool &lost,Cactus &cactus)
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
				set_delay();
			}
			else if(speed==2 and (score>=1250 and (cactus[0].posx-player.posx)%3==0))
			{
				set_delay();
			};	
			if(delay==0 and delay_active)
			{
				speed++;
				delay_active=false;
			}			
		}
		void jumping(int &i)
		{
			i=getch();
			if(i=='w' or i==' ' or i==KEY_UP)
			{
				player.jump_activate();
			}			
			player.jump(win);
		}
		void cacti_moving(int &speed, int &space)
		{
				if(!cactus[1].active and cactus[0].posx<=66-space and !delay_active)
				{
						cactus[1].rand_space(space);
						cactus[1].active=true;
				}
				if(!delay_active)
				{
					cactus[0].active=true;
				}
				cactus[0].cmove(win,speed,true);
				if(cactus[1].active)
				{
					cactus[1].cmove(win,speed,true);
				}
		}
		void set_delay()
		{
			if(!delay_active)
			{
				delay=66;
				delay_active=true;
			}
		}
		
		//window actions
		
		void set_variables_value()
		{
			height = 15;
			width = 70;
			cactus[0].active=true;
			cactus[1].active=false;
			score=0;
			speed=1;
			space=24;
			delay=0;
			delay_active=false;
			lost=false;
		}
		
		void window_initialisation()
		{
			initscr();
			keypad(stdscr, TRUE);
			curs_set(0);
			noecho();
			timeout(28);
			get_middle(stdscr,starty,startx,height,width);
			win =newwin(height,width,starty,startx);
			refresh();
			box(win,0,0);
			wrefresh(win);
			draw_ground();
		}
		
		void objects_setup()
		{
			for(auto i:cactus)
			{
				i.clean(win);
			}
			player.clean(win);
			cactus[0].rand_sprite();
			cactus[1].rand_sprite(highscore);
			player.prin(win);
			cactus[0].prin(win);
		}
		
		void printvar()
		{
			mvwprintw(win,1,1,"                    ");
			mvwprintw(win,1,1,"speed : %i",delay);
			wrefresh(win);
		}
		
		void game_end()
		{
			high_score();
			clear();
			cactus[0].rand_sprite();
			cactus[1].rand_sprite(highscore);
			delwin(win);
			endwin();
		}
	
};