/****************************************************************************
* Copyright © 2015 Alessandro Rosetti
* email: alessandro.rosetti@gmail.com
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
