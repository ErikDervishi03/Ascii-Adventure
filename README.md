git# P.project2023
Progetto di programmazione 2023 UniBO

NOTE:
-nelle mappe ci sono P per power-up, che dovranno essere diversi dai power-up che si comprano nello shop.

Collisioni:
-player/sparo ->elimina il player e se ha ancora vite lo mette nello spawn altrimenti viene una scritta game over 
-soldo/sparo  ->non succede nulla
-palyer/soldo ->se il soldo è una casella vicino al player lo prende
-bot/player   ->se il bot tocca il player lo scaraventa via
-nemico/soldo ->lo attraversa



TO DO:
-livello negozio
-powerup
-decidere possibilità per cosa puo succedere alla fine di mappa 5 livello 2
-mappa con i colori
-il formato in cui vengono salvati i dati si potrebbe ottimizzare ma cambierebbe veramente poco, fare se si ha voglia

ogni volta che si scrive codice bisogna per prima cosa fare : [git pull origin main] e quando si è finito di scrivere codice bisogna fare : [git push origin main] altrimenti bordello 
commit -a -m 'messaggio'

problemi:
-(difficile da replicare)se un nemico ti colpisce e spara allo stesso tempo diventi invisibile?(metti sulla quinta casella di una piattaforma partendo da sinistra, cosi ti spara e colpisce allo stesso tempo)


IDEE CONTINUO:(cio che succede dopo mappa 5 livello 2)
-incrementa la velocità dei bot
-cap sulla vita massima
-cap sui proiettili?


------------------------------------
Roadmap di gaia per il negozio
-implementare il costruttore.il costruttore prende 1)la finastra di gioco 2)il puntatore delle informazioni del player(vita,monete ecc..).Il puntatore si chiama Infoplayer,c'è una funzione che te lo ritorna che si trova il logic.public riga 34,questa funzione andrà richiamata quando apro il negozio

-funzione che ti permette di creare un menu a scelta(ad esempio) sotto alle informazione del player.Dovrai eliminare ciò che è al momento nello schermo e ci sono delle funzioni tipo int werase(WINDOW *win); che ti permettono di farlo.

dopodiche ti serviranno le funzioni che si avviano quando il giocatore sceglie di fare una cosa(ad esempio comprare vite)

-tutte le funzioni fanno dichiarate nel hpp e poi scritte nel cpp.le funzioni che ti servono solo per fare il negozio le metti in private, mentre le funzioni che dovrai richiamare in progetto.cpp le metti in public


-Infoplayer è un puntatore alla struttura dati player che si trova in Player.hpp

NEGOZIO: monete, colpi ,vite, punti
sezioni del negozio all interno dei quali devo creare funzioni per aumentare e diminuire le cose che ho comprato/speso -> private


COSA CI FACCIAMO CON I PUNTI?   discussione

cosa fare quando chiudo il negozio
