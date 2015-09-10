# Descrizione dei sorgenti

## scrabbleC
È l'eseguibile principale del gioco:
-  avvia/termina e controlla il thread master **game**;
-  avvia/termina il thread del tabellone **gameboard**;
-  avvia/sospende/termina i threads **player1** e **player2**;
-  smista i messaggi di interazione tra i 3 threads slave (gameboard, player1, player2);
-  invoca il comando **tiles** a ogni turno di gioco per estrarre le lettere per ogni player;
-  attiva la "clessidra" (**timer**) per ogni turno di gioco;
-  tiene il punteggio **score** della partita

Lista delle funzioni:
### startGame()
avvia una nuova partita (thread master)
### stopGame()
termina la partita in corso
### startGameboard()
avvia il thread del tabellone (thread slave)
### stopGameboard()
termina il thread del tabellone
### getGameboard()
chiede a gameboard di restituire la griglia del tabellone
### setGameboard()
dà al gameboard le istruzioni per posizionare le lettere di un player
### startPlayer()
avvia il thread di un player (thread slave) fornendo il set iniziale di tiles
### pausePlayer()
sospende il thread di un player (tempo scaduto e posizionamento tiles sul gameboard)
### resumePlayer()
riavvia il thread di un player (nuovo turno di gioco con nuove tiles e mappa aggiornata del gameboard)
### stopPlayer()
termina il thread di un player (fine partita)
### getTiles()
chiede a tiles un set di lettere N dal "sacchetto" per uno dei player
### startTimer()
avvia la clessidra per ogni turno di gioco
### getScore()
legge il punteggio attuale della partita
### setScore()
imposta il nuovo punteggio per il player

## gameboard
È l'eseguibile che gestisce il tabellone del gioco (griglia 15x15 da A1 a O15):
-  Quando inizializzato, carica in memoria la griglia vuota con la mappa delle **premiumSquare** (2/3 volte la lettera, 2/3 volte la parola);
-  A ogni turno di gioco memorizza l'occupazione delle celle;

Lista delle funzioni:
### init()
inizializza un nuovo tabellone all'inizio della partita
### get()
legge la mappa del tabellone
### set()
posiziona le lettere sul tabellone e restituisce un intero con il punteggio ottenuto dalla parola inserita nelle celle utilizzate della mappa

## tiles
È il comando che gestisce il "sacchetto delle lettere" per la partita, fornisce casualmente il numero N di tiles richiesti per ogni player

Lista delle funzioni:
### init()
inizializza il sacchetto delle lettere caricando il set per la lingua della partita
### get()
restituisce N tiles per un player

## player1 & player2
Sono gli eseguibili che contengono i 2 algoritmi di gioco (player1 predilige le parole con il maggior numero di lettere, player2 predilige le parole che totalizzano più punti). Ricevono le lettere e la mappa di gioco aggiornata a ogni turno e cercano nel dizionario le parole in base alle tiles a disposizione (sia quelle proprie che quelle già posizionate sul gameboard).

Lista delle funzioni:
### start()
avvia il thread all'inizio della partita
### pause()
sospende il thread quando il timer finisce il tempo a disposizione
### resume()
riavvia il thread con fornitura delle tiles mancanti e della gameboard aggiornata 
### stop()
termina il thread a fine partita
### getDictionary()
ottiene il dizionario completo oppure quello proprio del player dal comando dictionary
### setDictionary()
salva il dizionario proprio di ogni player; è consentito salvare solamente le parole che sono state considerate candidate al posizionamento sulla gameboard durante un turno di gioco; non è consentito indicizzare l'intero dizionario; il dizionario del player può essere ordinato per meglio rispondere al proprio algoritmo di gioco (

## dictionary
È il comando che gestisce l'accesso al dizionario per la lingua della partita e la scrittura dei dizionari di ogni player.

Lista delle funzioni:
### get()
restituisce il dizionario completo
### get(int player)
restituisce il dizionario di un player
### set(int player)
aggiunge elementi al dizionario di un player e li ordina secondo l'algoritmo proprio del player
