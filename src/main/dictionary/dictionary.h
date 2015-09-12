#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node
{
	struct node *left, *right;
	char *word;
} node;

typedef struct dictionary
{
	node **trees;
	int ntrees;
} dictionary;


dictionary* dictionary_open (const char *file);
void dictionary_close (dictionary* dict);

void dictionary_insert (dictionary *dict, char *word);
bool dictionary_search (dictionary* dict, char *word, bool prefix);

void dictionary_stats (dictionary *dict);

#endif
