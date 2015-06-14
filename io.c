
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


#include "io.h"


void draw_texture(int x, int y, Uint32 color,  SDL_Surface *screen)
{

	SDL_Rect rect = {x,y,20,20};

	SDL_FillRect(screen, &rect, color);	
}

void draw_tetr(int x_b, int y_b, int tetr[5][5],  SDL_Surface *screen)
{
	int i;
	int j;
	int a,b;
	int x = x_b*20;
	int y = y_b*20;
	Uint32 color = 0xAAAAAA;
	
	for(i =0; i < 5; i++)
	{
		y= y_b*20;
		for(j = 0; j < 5; j++)
		{
			if(tetr[i][j]>0)
			{
				draw_texture(x, y, color, screen);
			}
			y+=20;
		}
		x+=20;
	}
}

void draw_board(int x_b, int y_b, int board[WIDTH][HEIGHT],  SDL_Surface *screen)
{
	int i;
	int j;
	int x = x_b;
	int y = y_b;
	Uint32 color = 0xAAAAAA;


	for (i = 0;i < WIDTH; i++)
	{
		y = y_b;
		for(j = 0;j < HEIGHT; j++)
		{
			if(board[i][j]== 1)
		        {
				draw_texture(x, y, color, screen);
		        }
		y += 20;
		}
		x += 20;
	}
}


void draw_board_back(int x, int y, SDL_Surface *texture,  SDL_Surface *screen)
{

		SDL_Rect src, dest;


   
                 	src.x = x;
	                src.y = y;
	                src.w = texture->w;
	                src.h = texture->h;
	                dest = src;

		  SDL_BlitSurface(texture, &src, screen, &dest);

}

void draw_line_back(int x, int y, SDL_Surface *texture, SDL_Surface *screen)
{

		SDL_Rect src, dest;


	                src.x = 0;
	                src.y = 0;
	                src.w = texture->w;
	                src.h = texture->h;
	                dest.x = x;
			dest.y = y;
			dest.w = texture->w;
			dest.h = texture->h;

                        SDL_BlitSurface(texture, &src, screen, &dest);
}



void draw_line(int x, int y, int w, int h, SDL_Surface *screen)
{
	SDL_Rect rect = {x,y,w,h};

	SDL_FillRect(screen, &rect, 0xDDD000);
}


void draw_logo(int x, int y, SDL_Surface *texture, SDL_Surface *screen)
{

		SDL_Rect src, dest;


	                src.x = 0;
	                src.y = 0;
	                src.w = texture->w;
	                src.h = texture->h;
	                dest.x = x;
			dest.y = y;
			dest.w = texture->w;
			dest.h = texture->h;

                        SDL_BlitSurface(texture, &src, screen, &dest);
}




void draw_background(SDL_Surface *background,  SDL_Surface *screen)
{

	SDL_Rect src, dest;

	                /* Draw the background. */
	                src.x = 0;
	                src.y = 0;
	                src.w = background->w;
	                src.h = background->h;
	                dest = src;

			SDL_BlitSurface(background, &src, screen, &dest);

}

int Pollkey()
{
	SDL_Event event;
	while ( SDL_PollEvent(&event) ) 
	{
		switch (event.type) {
			case SDL_KEYDOWN:
				return event.key.keysym.sym;
		}
	}
	return 0;
}

void print_ttf(SDL_Surface *sDest, char* message, char* font, int size, SDL_Color color, SDL_Rect dest)
{

 TTF_Font *fnt = TTF_OpenFont(font, size);
 SDL_Surface *sText = TTF_RenderText_Blended( fnt, message, color);
 SDL_BlitSurface( sText,NULL, sDest,&dest );
 SDL_FreeSurface( sText );
 TTF_CloseFont( fnt );

}

void print_score(int score, SDL_Surface *screen)
{
        SDL_Color clr = {255,50,40,0};
	SDL_Rect dest = {540, 50,0,0};

	SDL_Color clr2 = {255,50,40,0};
	SDL_Rect dest2 = {420, 50,0,0};


	char buf[10];
	sprintf(buf,"%d", score*100);

	print_ttf(screen, "Score:", "courier.ttf", 25, clr2, dest2);

	print_ttf(screen, buf, "courier.ttf", 25, clr, dest);
}

void print_speed(int speed, SDL_Surface *screen)
{
        SDL_Color clr = {255,50,40,0};
	SDL_Rect dest = {540, 100,0,0};

	SDL_Color clr2 = {255,50,40,0};
	SDL_Rect dest2 = {420, 100,0,0};


	char buf[10];
	sprintf(buf,"%d", speed);

	print_ttf(screen, "Speed:", "courier.ttf", 25, clr2, dest2);

		
	print_ttf(screen, buf, "courier.ttf", 25, clr, dest);
}


void GameOver(SDL_Surface *screen)
{
	SDL_Color clr = {255,50,40,0};
	SDL_Rect dest = {150, 240,0,0};

	
	print_ttf(screen, "GameOver.", "courier.ttf", 46, clr, dest);

}
