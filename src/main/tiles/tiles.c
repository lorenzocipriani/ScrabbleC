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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "tiles.h"
#include "linkedlist.h"


/*
 * Stampa i primi n elementi del sacchettino
 */
void print_list(struct tile *tilesBag, int n)
{
	int i;
	
	if(tilesBag==NULL) {
		fprintf(stderr, "NULL!\n");
		return;
	}
	
	for(i=0; i<n; i++) {
		printf("%d-> %c\n", i, tilesBag->letter);
		tilesBag=tilesBag->n;
	}
}

/*
 * Inizializza il sacchetto delle lettere caricando il set per la lingua della partita.
 * Passare a questa funzione un puntatore a struct tile, la funzione modificherà gli elementi
 * puntati con una lista allocata in heap contenente le lettere già mischiate, pronte 
 * ad essere estratte.
 */
void init_tiles(struct tile **tilesBag)
{

	FILE *fp=NULL;
	struct tile temp;
	int n, i, z=0;
	char path[BUFSIZ];
	
		strcpy(path, LANGUAGE);
		strcat(path, ".tiles");
		
		printf("Carico file info tiles [%s]\n", path);	
		
		fp=fopen(path,"r");
		if(fp==NULL) {
			printf("%s\n",strerror(errno));
			exit(EXIT_FAILURE);
		}
		
		while(fscanf(fp, "%c %d %d\n", &temp.letter, &n, &temp.value)==3) {
			//printf("scanf: %c %d %d\n", temp.letter, n, temp.value);
			
			for(i=0; i<n; i++) {
				add(tilesBag, temp);
				
				z++;	
			}
		}
		
		fclose(fp);
		printf("Added %d letters\n", z);
		return;
}


/*
 * Restituisce un array di max 7 caselle contenente N tiles.
 */
struct tile *get_tiles(struct tile **tilesBag, int n)
{
	int i;
	static struct tile array[7];
	struct tile a;
	
		srand((unsigned)time(NULL));

		for(i=0; i<n; i++)
			array[i]=pop(tilesBag, rand()%99);
	
	return array;
}
