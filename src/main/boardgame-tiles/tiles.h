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
	struct tile *p;
	struct tile *n;
};

extern void print_list(struct tile *tilesBag, int n);
extern void init_tiles(struct tile **tilesBag);
extern struct tile *get_tiles(struct tile **tilesBag, int n);

#endif
