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
 * Modulo gestione lista  cicolare doppiamente linkata: "sacchettino" porta tiles
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "linkedlist.h"
#include "tiles.h"

void add(struct tile **head, struct tile element)	//test[OK]
{
	struct tile *aus=NULL;
		
		aus=(struct tile *)malloc(sizeof(struct tile));
		if(aus==NULL)
			fprintf(stderr,"%s\n",strerror(errno));
			
		aus->letter = element.letter;
		aus->value = element.value;
		
		if((*head)==NULL) {
			(*head)=aus;
			(*head)->p = (*head);
			(*head)->n = (*head);
		} else {
			if(((*head)->n == (*head)) && ((*head)->p == (*head))) {
				(*head)->n = aus;
				aus->p = (*head);
				(*head)->p = aus;
				aus->n = (*head);
			} else {
				((*head)->n)->p=aus;
				aus->n=((*head)->n)->p;
				(*head)->n=aus;
				aus->p=(*head);	
			}
		}
		return;
}

/*
 * Estrae dalla circular double linkedlist l'N-esimo elemento.
 * 
 * Ritorna: 
 * 	a) lettera '?' e int 0 -> Lista vuota
 *  b) il tile estratto 
 */
struct tile pop(struct tile **head, int n)	//test [OK]
{
	struct tile temp={'?',0};
	struct tile *aus=NULL;
	int i;
	
	
	if((*head)==NULL) {
	
		return temp;
	
	} else {
	
		if(((*head)->n == (*head)) && ((*head)->p == (*head))) {
			aus=(*head);
			temp.letter=(*head)->letter;
			temp.value=(*head)->value;
			free(aus);
			(*head)=NULL;
			return temp;
			
		} else {
			for(i=0; i<n; i++, (*head)=(*head)->n);
			aus=(*head);
			((*head)->p)->n=(*head)->n;
			((*head)->n)->p=(*head)->p;
			
			temp.letter=(*head)->letter;
			temp.value=(*head)->value;
			
			(*head)=(*head)->n;
			
			free(aus);
			
			return temp;
		}
		
	}
}
