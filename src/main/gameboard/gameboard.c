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

#include "gameboard.h"

void print_gameboard(struct square gameboard[15][15])
{
	int i,z;
	
	printf("     A     B     C     D     E     F     G     H     I     J     K     L     M     N     O\n");
	
	for(i=0; i<15; i++) {
		
		//qui ci sta un flag di printf per allineare, ma non lo trovo, quindi soluzione Sparta
		if(i<10)
			printf(" %d ", i);
		else
			printf("%d ", i);
			
		for(z=0; z<15; z++) {
			printf("[%s:%c]", gameboard[i][z].bonus, gameboard[i][z].tile.letter);
		}
		printf("\n\n");
	}
	
	
}

static void put_bonusInSquare(struct square gameboard[15][15])
{
	//Add Start Square
	strcpy(gameboard[7][7].bonus,"@@");
	
	//Bonus 3xWS
	strcpy(gameboard[0][0].bonus,"3W");
	strcpy(gameboard[0][7].bonus,"3W");
	strcpy(gameboard[0][14].bonus,"3W");
	strcpy(gameboard[7][0].bonus,"3W");
	strcpy(gameboard[7][14].bonus,"3W");
	strcpy(gameboard[14][0].bonus,"3W");
	strcpy(gameboard[14][7].bonus,"3W");
	strcpy(gameboard[14][14].bonus,"3W");
	
	//Bonus 2xWS
	strcpy(gameboard[1][1].bonus,"2W");
	strcpy(gameboard[1][13].bonus,"2W");
	strcpy(gameboard[2][2].bonus,"2W");
	strcpy(gameboard[2][12].bonus,"2W");
	strcpy(gameboard[3][3].bonus,"2W");
	strcpy(gameboard[3][11].bonus,"2W");
	strcpy(gameboard[4][4].bonus,"2W");
	strcpy(gameboard[4][10].bonus,"2W");
	strcpy(gameboard[10][4].bonus,"2W");
	strcpy(gameboard[10][10].bonus,"2W");
	strcpy(gameboard[11][3].bonus,"2W");
	strcpy(gameboard[11][11].bonus,"2W");
	strcpy(gameboard[12][2].bonus,"2W");
	strcpy(gameboard[12][12].bonus,"2W");
	strcpy(gameboard[13][1].bonus,"2W");
	strcpy(gameboard[13][13].bonus,"2W");
	
	//Bonus 3xLS
	strcpy(gameboard[1][5].bonus,"3L");
	strcpy(gameboard[1][9].bonus,"3L");
	strcpy(gameboard[5][1].bonus,"3L");
	strcpy(gameboard[5][5].bonus,"3L");
	strcpy(gameboard[5][9].bonus,"3L");
	strcpy(gameboard[5][13].bonus,"3L");
	strcpy(gameboard[9][1].bonus,"3L");
	strcpy(gameboard[9][5].bonus,"3L");
	strcpy(gameboard[9][9].bonus,"3L");
	strcpy(gameboard[9][13].bonus,"3L");
	strcpy(gameboard[13][5].bonus,"3L");
	strcpy(gameboard[13][9].bonus,"3L");
	
	//Bonus 2xLS
	strcpy(gameboard[0][3].bonus,"2L");
	strcpy(gameboard[0][11].bonus,"2L");
	strcpy(gameboard[2][6].bonus,"2L");
	strcpy(gameboard[2][8].bonus,"2L");
	strcpy(gameboard[3][0].bonus,"2L");
	strcpy(gameboard[3][7].bonus,"2L");
	strcpy(gameboard[3][14].bonus,"2L");
	strcpy(gameboard[6][2].bonus,"2L");
	strcpy(gameboard[6][6].bonus,"2L");
	strcpy(gameboard[6][8].bonus,"2L");
	strcpy(gameboard[6][12].bonus,"2L");
	strcpy(gameboard[7][3].bonus,"2L");
	strcpy(gameboard[7][11].bonus,"2L");
	strcpy(gameboard[8][2].bonus,"2L");
	strcpy(gameboard[8][6].bonus,"2L");
	strcpy(gameboard[8][8].bonus,"2L");
	strcpy(gameboard[8][12].bonus,"2L");
	strcpy(gameboard[11][0].bonus,"2L");
	strcpy(gameboard[11][7].bonus,"2L");
	strcpy(gameboard[11][14].bonus,"2L");
	strcpy(gameboard[12][6].bonus,"2L");
	strcpy(gameboard[12][8].bonus,"2L");
	strcpy(gameboard[14][3].bonus,"2L");
	strcpy(gameboard[14][11].bonus,"2L");
	
}

//si poteva fare più elegante, lo so..
static void put_dataInSquares(struct square gameboard[15][15])
{
	int i;
	
	
		for(i=0; i<15; i++) {
			gameboard[i][0].column='A';
			gameboard[i][0].tile.letter=' ';
			gameboard[i][0].tile.value=0;
			gameboard[i][0].tile.n=NULL;
			strcpy(gameboard[i][0].bonus,"  ");
		
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][1].column='B';
			gameboard[i][1].tile.letter=' ';
			gameboard[i][1].tile.value=0;
			gameboard[i][1].tile.n=NULL;
			strcpy(gameboard[i][1].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][2].column='C';
			gameboard[i][2].tile.letter=' ';
			gameboard[i][2].tile.value=0;
			gameboard[i][2].tile.n=NULL;
			strcpy(gameboard[i][2].bonus,"  ");
		
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][3].column='D';
			gameboard[i][3].tile.letter=' ';
			gameboard[i][3].tile.value=0;
			gameboard[i][3].tile.n=NULL;
			strcpy(gameboard[i][3].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][4].column='E';
			gameboard[i][4].tile.letter=' ';
			gameboard[i][4].tile.value=0;
			gameboard[i][4].tile.n=NULL;
			strcpy(gameboard[i][4].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][5].column='F';
			gameboard[i][5].tile.letter=' ';
			gameboard[i][5].tile.value=0;
			gameboard[i][5].tile.n=NULL;
			strcpy(gameboard[i][5].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][6].column='G';
			gameboard[i][6].tile.letter=' ';
			gameboard[i][6].tile.value=0;
			gameboard[i][6].tile.n=NULL;
			strcpy(gameboard[i][6].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][7].column='H';
			gameboard[i][7].tile.letter=' ';
			gameboard[i][7].tile.value=0;
			gameboard[i][7].tile.n=NULL;
			strcpy(gameboard[i][7].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][8].column='I';
			gameboard[i][8].tile.letter=' ';
			gameboard[i][8].tile.value=0;
			gameboard[i][8].tile.n=NULL;
			strcpy(gameboard[i][8].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][9].column='J';
			gameboard[i][9].tile.letter=' ';
			gameboard[i][9].tile.value=0;
			gameboard[i][9].tile.n=NULL;
			strcpy(gameboard[i][9].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][10].column='K';
			gameboard[i][10].tile.letter=' ';
			gameboard[i][10].tile.value=0;
			gameboard[i][10].tile.n=NULL;
			strcpy(gameboard[i][10].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][11].column='L';
			gameboard[i][11].tile.letter=' ';
			gameboard[i][11].tile.value=0;
			gameboard[i][11].tile.n=NULL;
			strcpy(gameboard[i][11].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][12].column='M';
			gameboard[i][12].tile.letter=' ';
			gameboard[i][12].tile.value=0;
			gameboard[i][12].tile.n=NULL;
			strcpy(gameboard[i][12].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][13].column='N';
			gameboard[i][13].tile.letter=' ';
			gameboard[i][13].tile.value=0;
			gameboard[i][13].tile.n=NULL;
			strcpy(gameboard[i][13].bonus,"  ");
		}
		
		for(i=0; i<15; i++) {
			gameboard[i][14].column='O';
			gameboard[i][14].tile.letter=' ';
			gameboard[i][14].tile.value=0;
			gameboard[i][14].tile.n=NULL;
			strcpy(gameboard[i][14].bonus,"  ");
		}
		
	put_bonusInSquare(gameboard);
}



/*
 * Inizializza un nuovo tabellone all'inizio della partita.
 * Tabellone con righe [0-14] e colonne [A-O]
 *
 */
 void init_gameboard(struct square gameboard[15][15])
 {
 	put_dataInSquares(gameboard);
 
 }
 
 
 /*
  * Calcola punteggio parola avendo un array di struct square
  * già settate dal player inviante con, appunto, le lettere
  * da calcolare e inserire in tabellone.
  * Accetta in ingresso, inoltre, un int relativo alla lunghezza
  * della parola (es. ciao -> 4).
  */
 static int calculate_score(struct square word[], int n)
 {
 	int i, wordMultiplier=1;
 	unsigned short int score=0;
 	
 		for(i=0; i<n; i++) {
			//se in campo bonus: "  " -> nessun bonus
			if(strcmp(word[i].bonus, "  ")==0) {
				score+=word[i].tile.value;
			} else {
				if(strcmp(word[i].bonus, "3W")==0) {
					score+=word[i].tile.value;
					wordMultiplier=wordMultiplier*3;
				} else {
					if(strcmp(word[i].bonus, "2W")==0) {
						score+=word[i].tile.value;
						wordMultiplier=wordMultiplier*2;
					} else {
						if(strcmp(word[i].bonus, "3L")==0) {
							score+=(word[i].tile.value*3);
						} else {
							if(strcmp(word[i].bonus, "2L")==0) {
								score+=(word[i].tile.value*2);
							}
						}
					}
				}
			}
 		}	
 		score*=wordMultiplier;
 
		return score;
 }





/*
 * Accetta in ingresso la gameboard non modificata, la gameboard modificata
 * e il numero di lettere inserite. Aggiorna la mappa e ritorna il punteggio 
 * della parola inserita
 */
int setOnMap_getScore(struct square oldgameboard[15][15], struct square newgameboard[15][15], int n)
{
	struct square word[n];
	int i,j,z=0;
	
	//confronta le due boardgame ed estrae un array con le parole inserite
	for(i=0; i<15; i++) {
		for(j=0; j<15; j++) {
			if(oldgameboard[j][i].tile.letter != newgameboard[j][i].tile.letter) {
				word[z++]=newgameboard[j][i];
			}
		}
	}
	
	//aggiorna la nuova gameboard
	for(i=0; i<15; i++) {
		for(j=0; j<15; j++) {
			if(oldgameboard[j][i].tile.letter != newgameboard[j][i].tile.letter) {
				oldgameboard[j][i]=newgameboard[j][i];
			}
		}
	}
	
	return calculate_score(word,n);
}
