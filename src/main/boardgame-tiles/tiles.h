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

#ifndef _TILES_H
#define _TILES_H

/*
 * Qui sta un define linguaggio, in modo tale da andarsi a cercare il file relativo al
 * numero esatto di lettere-tile, file in /data/tile-languages
 */
#define LANGUAGE "it"


/*
 * Elemento lista circolare doppiamente linkata "tile"
 */
struct tile {
	char letter;
	unsigned short int value;
	struct tile *n;
};

extern void print_list(struct tile *tilesBag, int n);
extern void init_tiles(struct tile **tilesBag);
extern struct tile *get_tiles(struct tile **tilesBag, int n);

#endif
