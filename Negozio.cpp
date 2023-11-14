#include "hpp-files/Negozio.hpp"

Negozio::Negozio(WINDOW* win,Entities* MyEntities) {
    curwin = win;
    entitiesOBJ = MyEntities;
    InfoPlayer  = entitiesOBJ->ReturnPlayerOBJ();
}
void Negozio::updateVariables(){
    InfoPlayer  = entitiesOBJ->ReturnPlayerOBJ();
}
int Negozio::create_Shop() {
    int highlight = 0;
    int scelta = 0;

    while (true) {
        updateVariables();
        entitiesOBJ->DisplayPlayerStats();
        displayMenu( highlight);

        scelta = wgetch(curwin);
        switch (scelta) {
            case KEY_UP:
                highlight = (highlight - 1 + 5) % 5;
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % 5;
                break;
            case 10: // Enter
                eventiShop(highlight);
                break;
            case 27: // Esc
                return -1; // Exit the function
            default:
                break;
        }
    }

    wrefresh(curwin);
    return highlight;
}

void Negozio::displayMenu(int highlight) {
    const char scelte[] = "|BUY|";
    for (int i = 0; i < 5; i++) {
        if (i == highlight) {
            wattron(curwin, A_REVERSE);
        }
        mvwprintw(curwin, 1 + (3 * (i + 1)), 3, scelte);
        if (i == highlight) {
            wattroff(curwin, A_REVERSE);
        }
    }
}


void Negozio::eventiShop(int scelta){
    if(InfoPlayer){
        switch(scelta){
            case 0://20 hp
                if(InfoPlayer->Money>0){
                    if(InfoPlayer->hp<=80){
                        if(InfoPlayer->hp>0){
                            InfoPlayer->hp+=20;
                            InfoPlayer->Money-=1;
                        }
                        else mvwprintw(curwin, 9, 55, "%s", "Sei morto! Iniza una nuova partita!");
                    }
                    else if (mvwprintw(curwin, 9, 65, "%s", "Hai già vita al massimo!"));
                }else mvwprintw(curwin, 9, 65, "%s", "Non hai abbastanza monete!");
                break;
            case 1://5 proiettili
                if(InfoPlayer->Money>1){
                    if(InfoPlayer->hp>0){
                        InfoPlayer->colpi+=5;
                        InfoPlayer->Money-=2;
                    }else mvwprintw(curwin, 10, 55, "%s", "Sei morto! Iniza una nuova partita!");
                }else mvwprintw(curwin, 10, 65, "%s", "Non hai abbastanza monete!");
                break;
            case 2://shield
                /*if(InfoPlayer->Money>1){
                    if(InfoPlayer->shield<80){
                        InfoPlayer->shield+=20;
                        InfoPlayer->Money-=2;
                    }
                    else if(InfoPlayer->shield<100){
                        InfoPlayer->shield=100;
                        InfoPlayer->Money-=2;
                    }
                } */
                break;
            case 3:
                if(InfoPlayer->Money>2){
                    if(InfoPlayer->hp>0){
                        InfoPlayer->Money-=3;
                        //aggiornare curmap. Come?
                        //aggiornare anche la posizione del player per non farlo spawnare dov'era nella mappa vecchia
                    }else mvwprintw(curwin, 12, 55, "%s", "Sei morto! Iniza una nuova partita!");
                }else mvwprintw(curwin, 12, 65, "%s", "Non hai abbastanza monete!");
                break;
            case 4:
                break;
            default:
                break;
        }
    }
}

void Negozio::buyshots(){   
//int hp = 100;
//    int Money = 0;
//  int colpi = 10;
  
}

void Negozio::buyLives(){   
    //int hp = 100;
}




/*

====================================================================================================
|             (  ____ \    (  )    (  )    /         \     (  ____  )                              |
|             | (   \/     |  |    |  |   (    ___    )    | (    ) |                              |
|             | (_____     |  (____)  |   |   /   \   |    | (____) |                              |
|             (_____  )    |   ____   |   |  |     |  |    |  ______)                              |
|                   ) |    |  (    )  |   |   \___/   |    |  |                                    |
|             /\____) |    |  |    |  |   (           )    |  |                                    |
|             \_______)    (__)    (__)    \_________/     (__)                                    |
|                                                                                                  |
|                                                                                                  |
|      ACQUISTA VITE:                  ACQUISTA COLPI                   ACQUISTA ARMATURA:         |
|                                                                                                  |
|    1 vita = 20 monete              1 colpo = 10 monete              1 armatura = 30 monete       |
|                                                                                                  |
|   10 vite =  150 monete           10 colpi = 50 monete              5 armature=  100 monete      |
|                                                                                                  |
|                                                                                                  |
====================================================================================================

*/


