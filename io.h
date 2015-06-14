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


//#include "tetr.h"
#include "board.h"
#include <SDL.h>
#include "SDL_ttf.h"


void draw_texture(int x, int y, Uint32 color,  SDL_Surface *screen);

void draw_tetr(int x_b, int y_b, int tetr[5][5],  SDL_Surface *screen);

void draw_board(int x_b, int y_b, int board[WIDTH][HEIGHT],  SDL_Surface *screen);

void draw_board_back(int x_b, int y_b, SDL_Surface *texture,  SDL_Surface *screen);

void draw_line_back(int x, int y, SDL_Surface *texture, SDL_Surface *screen);

void draw_line(int x, int y, int w, int h, SDL_Surface *screen);

void draw_logo(int x, int y, SDL_Surface *texture, SDL_Surface *screen);

void draw_background(SDL_Surface *background,  SDL_Surface *screen);

int Pollkey();

void print_ttf(SDL_Surface *sDest, char* message, char* font, int size, SDL_Color color, SDL_Rect dest);

void print_score(int score, SDL_Surface *screen);


void print_speed(int speed, SDL_Surface *screen);


void GameOver(SDL_Surface *screen);

