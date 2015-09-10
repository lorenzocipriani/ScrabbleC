/*  Distributore delle lettere */

typedef struct
{
	int intPoints;
	int intAvailable;
} tile;

typedef struct
{
	char *charLetter;
	tile *tileTuple;
} tiles;
