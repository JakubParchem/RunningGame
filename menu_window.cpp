#include "drawable.cpp"

class Menu
{
	bool first_time=true;
	bool playing=true;
	bool up;
	bool a;
	Drawable arrow;
	int height,width,starty,startx;
	WINDOW *win;
	public:
	void start(int highscore,int score)
	{
		window_setup();
		if(!first_time)
		{
			print_score(highscore, score);
		}
		select();
		clear();
		delwin(win);
		endwin();
	}
	bool is_quiting()
	{
		if(!playing)
		{
			return true;
		}
		return false;
	}	
	void draw_title()
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
	void select()
	{
		arrow.setsprite("<");
		int i=0;
		up=true;
		if(first_time)
		{
			arrow.setpos(12,23);
			mvwprintw(win,12,18,"PLAY");
			mvwprintw(win,15,18,"QUIT");
			wrefresh(win);
			a=true;
			key_input(a);
			
			if(!up)
			{
				playing=false;	
			}
		}
		else
		{
			arrow.setpos(14,26);
			mvwprintw(win,14,15,"PLAY AGAIN");
			mvwprintw(win,17,18,"QUIT");
			wrefresh(win);
			a=true;
			key_input(a, 3);
			
			if(!up or i=='q')
			{
				playing=false;	
			}
		}	
		first_time=false;
	}
	void print_score(int highscore,int score)
	{
		mvwprintw(win,12,5,"Highscore: %i  Last Score: %i",highscore,(score/4));
		wrefresh(win);
	}
	void window_setup()
	{
		set_variables_values();
		window_initialisation();
		draw_title();
	}
	void window_initialisation()
	{
		initscr();
		curs_set(0);
		keypad(stdscr, TRUE);
		timeout(1000000000);
		noecho();
		get_middle(stdscr,starty,startx,height,width);
		win =newwin(height,width,starty,startx);
		refresh();
		box(win,0,0);
		wrefresh(win);
	}
	void set_variables_values()
	{
		height = 20;
		width = 41;
	}
	void key_input(bool &a, int x=0)
	{
		int i=0;
		while(a)
			{
				arrow.prin(win);
				i=getch();
				switch(i)
				{
					case 'w':
					case KEY_UP:
						{
							if(!up)
							{
								up=true;
								arrow.move_right(win,x);
								arrow.move_up(win,3);	
							}
							break;
						}
					case 's':
					case KEY_DOWN:
						{
							if(up)
							{
								up=false;
								arrow.move_down(win,3);
								arrow.move_left(win,x);
							}
							break;
						}
					case 'e':
					case ' ':
					case 'q':
						{
							a=false;
							break;
						}
				}
			}
	}
};