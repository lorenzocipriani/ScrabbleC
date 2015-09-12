/*  Processo principale del gioco e controller dei thread giocatori (player1 e player2) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "scrabbleC.h"
#include "../dictionary/dictionary.h"


int main()
{
    dictionary *dict = dictionary_new();
    
    dictionary_open(dict, "data/dictionary.txt");
    
	exit(EXIT_SUCCESS);
}
