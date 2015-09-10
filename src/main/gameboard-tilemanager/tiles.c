/*  Distributore delle lettere */

typedef struct
{
	char *charLetter;
	int intPoints;
	int intAvailable;
} tile;

typedef struct
{
	tile[] *tileTuple;
} tiles;
