#Interfacciarsi al programma Gameboard

Il programma **GameBoard** si occupa di:
- gestire il "sacchettino" porta tiles.
- gestire il "tabellone" di gioco.
 
Questo programma resta in ascolto di coda di messaggi standard POSIX (stringa):
(http://www.math.hcmuns.edu.vn/~vdchai/web/Wrox_-_Beginning_Linux_Programming_4th_Edition_%282008%29.pdf - pagina 594)

a) **init_tiles()**
	Ritorna: niente
	Azione: Inizializza il sacchettino per iniziare a giocare
	
b) **get_tiles(int numeroditiles)**
	Ritorna: struct tile array[numeroditiles]
	Azione: come sopra + elimina i tiles gettati dal sacchettino
	
c) **init_gameboard()**
	Ritorna: niente
	Azione: Inizializza il tabello di gioco
	
d) **get_boardgame()**
	Ritorna: struct tile boardgame[15][15]
	Azione: come sopra
	
e) **setBoardgame_getScore(struct tile boardmodificata, int lunghezzaparolainserita)**
	Ritorna: int punteggio
	Azione: calcola punteggio e aggiorna il tabellone dentro il processo gameBoard.
		stampa, inoltre, nella console il tabellone aggiornato.
		
f) **stop**
	Ritorna: niente
	Azione: chiude la coda di messaggi e termina.
	
	
	
##ATTENZIONE: 
Quanto ti interfacci con l'eseguibile inviando una stringa relativa
ad un comando che ritorna qualcosa, **ricorda** di mettere il programma
che si interfaccia con GameBoard in attesa di una risposta :D



									Aleks il Bello ù.ù
