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


int tetrs[7 /*kind */ ][4 /* rotation */ ][5 /* horizontal blocks */ ][5 /* vertical blocks */ ];

void next_tetr(int num_tetr, int num_rotation, int tetr[5][5]);
