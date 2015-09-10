# ScrabbleC
Scrabble game computer vs computer

### Descrizione
Si tratta di realizzare il gioco dello Scarabeo (scrabbleC) dove un computer (player1) gioca contro un altro computer (player2). La differenza tra i due giocatori è che player1 ha un algoritmo che predilige le parole con il maggior numero di lettere, mentre player2 predilige le parole che totalizzano più punti.
I due giocatori hanno a disposizione lo stesso dizionario di vocaboli (dictionary), ma non possono caricarlo e indicizzarlo in memoria in fase di avvio. Per ogni turno di gioco, il dizionario deve essere scorso nella maniera più efficiente possibile per l'algoritmo di gioco di ogni player. Le parole individuate durante un turno di gioco possono essere conservate in memoria per consultazione prioritaria rispetto al dizionario nei turni di gioco successivi.

### Standards
La sintassi per il compilatore è lo standard [ANSI C rev.11] (https://en.wikipedia.org/wiki/C11_(C_standard_revision)).

Lo standard di codifica segue le linee guida [Gnu Coding Standard] (http://www.gnu.org/prep/standards/standards.html).

Il layout del repository software è il seguente:
- **bin**: cartella di output per gli eseguibili prodotti al termine della compilazione, il contenuto non va distribuito su git (.gitignore)
  - **bin/lib**: cartella di output per le librerie di progetto, il contenuto non va distribuito su git (.gitignore)
- **build**: cartella di output dove avviene la compilazione (creazione file oggetto: *.o), il contenuto non va distribuito su git (.gitignore)
- **conf**: file di configurazione
- **data**: file di dati e strutture (es.: dizionario italiano, inglese, etc)	
- **doc**: documentazione e note
- **lib**: contiene le librerie esterne necessarie al progetto
  - **lib/src**: contiene il codice delle librerie sviluppate per il progetto
- **res**: file statici delle risorse
- **src**: contiene i sorgenti del progetto suddivisi in:
  - **src/main**: file di progetto
  - **src/test**: file per i test unitari

Per dare nomi a variabili e funzioni si usa la lingua inglese perché le parole generalmente sono più corte rispetto all'italiano.