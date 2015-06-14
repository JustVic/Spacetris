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


/*board.h*/
#include "tetr.h"

#define HEIGHT 20
#define WIDTH 14

void init_board(int board[WIDTH][HEIGHT]);

int IsPossMoveRight(int p_x, int p_y, int board[WIDTH][HEIGHT], int tetr[5][5]);

int IsPossMoveLeft(int p_x, int p_y, int board[WIDTH][HEIGHT], int tetr[5][5]);

int IsPossMoveDown(int p_x, int p_y, int board[WIDTH][HEIGHT], int tetr[5][5]);

int IsPossRotate(int p_x, int p_y, int num_tetr, int rotation, int board[WIDTH][HEIGHT], int tetr[5][5]);

int delete_line(int board[WIDTH][HEIGHT]);

void Store_tetr(int p_x, int p_y, int board[WIDTH][HEIGHT], int tetr[5][5]);

