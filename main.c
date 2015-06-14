
//  Spacetrix
//  made by AkylaQD.
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "io.h"

#define MAX_SPEED 6
#define WAIT_TIME 700

SDL_Surface *screen;



int main(int argc, char *argv[])
{
        Uint8 *keystate;
	SDL_Surface *temp;
	SDL_Surface *background;
	SDL_Surface *board_text;
	SDL_Surface *line_text;
	SDL_Surface *menu;
	SDL_Surface *logo;


	int speed = 0;

	int frames = 0;
	Uint8 v_bpp;
	const SDL_VideoInfo *v_info;
	int score=0;

	int y=3;
	int x=5;
	int quit=0;

	
	unsigned long time1 = SDL_GetTicks();
	unsigned long time2;
	int mKey;


	int rotation;
	int num_tetr;
	int num_next_tetr;


	int board[WIDTH][HEIGHT];
	int tetr[5][5];
	int nextTetr[5][5];

	int flag1=0;
	int i;
	int flag2=0;

	srand(time1);

	rotation = rand()%4;
	num_tetr = rand()%7;
	num_next_tetr = rand()%7;


	// Initialize SDL's video system 
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
 
	atexit(SDL_Quit);

	v_info = SDL_GetVideoInfo();
	if ( v_info->vfmt->BitsPerPixel > 8 )
       	{
		v_bpp = v_info->vfmt->BitsPerPixel;
	}
       	else
	{
		v_bpp = 16;
	}

	// set a 640x480  video mode 
	screen = SDL_SetVideoMode(640, 480, v_bpp, SDL_DOUBLEBUF | SDL_HWSURFACE);
	if (screen == NULL) 
	{
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}

	SDL_WM_SetCaption("Spacetris v.1", "Icon Title");

	 TTF_Init();
         atexit(TTF_Quit);


	temp = SDL_LoadBMP("./images/background.bmp");
	background = SDL_DisplayFormat(temp);
	if (background == NULL)
	{
		printf("Unable to load bitmap.\n");
		return 1;
	}


	SDL_FreeSurface(temp);


	temp = SDL_LoadBMP("./images/Board.bmp");
	board_text = SDL_DisplayFormat(temp);
	if (temp == NULL)
	{
		printf("Unable to load\n");
		return 1;
	}

	SDL_FreeSurface(temp);


	temp = SDL_LoadBMP("./images/line.bmp");
	line_text = SDL_DisplayFormat(temp);
	if (temp == NULL)
	{
		printf("Unable to load\n");
		return 1;
	}

	SDL_FreeSurface(temp);

	temp = SDL_LoadBMP("./images/SpV1.bmp");
	logo = SDL_DisplayFormat(temp);
	if (temp == NULL)
	{
		printf("Unable to load\n");
		return 1;
	}

	SDL_FreeSurface(temp);


	init_board(board);

	next_tetr(num_tetr, rotation, tetr);
	next_tetr(num_next_tetr, rotation, nextTetr);



	
	while(quit == 0)
	{
		SDL_PumpEvents();

		keystate = SDL_GetKeyState(NULL);

		if ( keystate[SDLK_q] || keystate[SDLK_ESCAPE])
		{
			quit = 1; 
		}


		time2 = SDL_GetTicks();
	        if((time2-time1) > (WAIT_TIME-100*speed))
		{
			//Move Down
			if (IsPossMoveDown(x, y, board, tetr)!=0)
			{
				Store_tetr(x, y, board, tetr);
				y=0;
				x=5;
				num_tetr=num_next_tetr;
				num_next_tetr=rand()%7;
				next_tetr(num_tetr, rotation, tetr);
				next_tetr(num_next_tetr, rotation, nextTetr);
				score+=delete_line(board);
				if(((score%10)==0)&& score!=0)
				{
					if((speed<6) && flag1==0)
					{
						flag1=1;
						speed+=1;
					}
				}
				else
				{
			        	flag1=0;
				}
			}
			y+=1;
			time1 = SDL_GetTicks();

		}
		else
		{
			for(i=0; i<14; i++)
					{
				        	if(board[i][3]==1)
						{
							flag2=1;
						}
					}

		}

		mKey = Pollkey();

		switch(mKey)
		{

			case(SDLK_UP):
		{
			//Rotate
			if(IsPossRotate(x, y, num_tetr, rotation+1, board, tetr)==0)
			{
			
			if(rotation!=3)
			{
				rotation +=1;
			        next_tetr(num_tetr, rotation, tetr);
				break;
			}
			else
			{
				rotation=0;
				next_tetr(num_tetr, rotation, tetr);
				break;
			}
			}
			break;

		}

			case(SDLK_LEFT):
		{
			//Move Left
			if(IsPossMoveLeft(x, y, board, tetr)==0)
				       {   
					       x-=1;
					       break;
				       }
			break;
			
		}
			case(SDLK_RIGHT):
		{
			//Move right
			       if(IsPossMoveRight(x, y, board, tetr)==0)
			       {
				       x+=1;
				       break;
			       }
			       break;
			/*case(SDLK_R):
			       {
			      
				       if(flag2==1)
				       {
					       
		                       }
			       }*/

		}
		}

		
	      

                        /* All drawnings */

		        draw_background(background,  screen);

			draw_board_back(0, 0, board_text,  screen);
			
		        draw_line_back(340, 390, line_text, screen);

			draw_line(355, 400, (score%10)*25, 20, screen);

			draw_logo(300, 200, logo, screen);

			draw_tetr(x, y, tetr,  screen);
			
			draw_tetr(15, 2, nextTetr, screen);

			draw_board(0, 0, board, screen); 	

			
			print_score(score, screen);

			print_speed(speed, screen);

			if(flag2==1)
			{
				GameOver(screen);
			}

			
	                SDL_Flip(screen);
			if(frames==60000)
			{
				frames=0;
			}
		frames++;	
	}

	SDL_FreeSurface(background);
	return 0;
}
