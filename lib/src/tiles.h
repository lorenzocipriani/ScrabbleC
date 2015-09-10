#ifndef _TILES_H
#define _TILES_H

/*
 * Qui sta un define linguaggio, in modo tale da andarsi a cercare il file relativo al
 * numero esatto di lettere-tile, file in /data/tile-languages
 */
#define LANGUAGE "it"

struct tile {
	char letter;
	short int value;
};

extern void init_tiles(void);
extern char *get_tiles(int n);

#endif
