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

/*
 * Modulo gestione lista  cicolare mono linkata: "sacchettino" porta tiles
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "tiles.h"
#include "linkedlist.h"

void add(struct tile **head, struct tile element)
{
	struct tile *aus=NULL;
		
		aus=(struct tile *)malloc(sizeof(struct tile));
		if(aus==NULL) {
			fprintf(stderr,"%s\n",strerror(errno));
			exit(EXIT_FAILURE);
			}
			
		aus->letter = element.letter;
		aus->value = element.value;
		
		if((*head)==NULL) {
			(*head)=aus;
			(*head)->n = (*head);
		} else {
			if((*head)->n == (*head)) {
				(*head)->n = aus;
				aus->n = (*head);
			} else {
				aus->n=(*head)->n;
				(*head)->n=aus;
			}
		}
		(*head)=aus;
		return;
}

/*
 * Estrae dalla circular linkedlist l'N-esimo elemento.
 * 
 * Ritorna: 
 * 	a) lettera '?' e int 0 -> Lista vuota
 *  b) il tile estratto 
 */
struct tile pop(struct tile **head, int n)
{
	struct tile temp={'?',0};
	struct tile *aus=NULL, *vice=NULL;
	int i;
	
	
	if((*head)==NULL) {
	
		return temp;
	
	} else {
	
		if((*head)->n == (*head)) {
			aus=(*head);
			temp.letter=(*head)->letter;
			temp.value=(*head)->value;
			free(aus);
			(*head)=NULL;
			return temp;
			
		} else {
			vice=(*head);
			for(i=0; i<n; i++, (*head)=(*head)->n) {
				if(i>0)
					vice=vice->n;
			}
			
			vice->n=(*head)->n;
			
			temp.letter=(*head)->letter;
			temp.value=(*head)->value;
			
			free(aus);
			
			return temp;
		}
		
	}
}
