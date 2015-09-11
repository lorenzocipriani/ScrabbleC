/****************************************************************************
* Copyright © 2015 Alessandro Spallina
* email: alessandrospallina1@gmail.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
****************************************************************************/

#ifndef _GAMEBOARD_H
#define _GAMEBOARD_H

#include "tiles.h"


struct square {
	char column;
	char bonus[5];
	struct tile tile;
};

extern void print_gameboard(struct square gameboard[15][15]);
extern void init_gameboard(struct square gameboard[15][15]);
extern int setOnMap_getScore(struct square oldgameboard[15][15], struct square newgameboard[15][15], int n);


#endif
