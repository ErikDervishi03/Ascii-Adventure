#include "hpp-files/Mappa.hpp"
#include <fstream>
#include <iostream>

Mappa::Mappa(WINDOW * win){
    playwin=win;
    keypad(playwin, true);
    for(int xM=0;xM<xMaxG;xM++){
        for(int yM=0;yM<yMaxG;yM++){
            Matrice[xM][yM]=' ';
        }
    }
};

void Mappa::stampamappa(){//deve venire chiamata all'inizio quando una mappa deve apparire e quando il player cambia mappa  
    int yM;
    int xM;
    for(xM=1;xM<=xMaxG;xM++){
        for(yM=1;yM<=yMaxG;yM++){
            mvwaddch(playwin, yM, xM, Matrice[xM-1][yM-1]);
        }
    }
    return;
}

void Mappa::leggimappa(int curmap){
    char mychar;
    int i=0;
    int j=-1;
    std::ifstream myfile;
    myfile.open("mockup.mappa.txt");
    if(curmap!=10){
        do{
            mychar=myfile.get();
        }while((mychar - '0')!=curmap && myfile.good());
    }else{
        do{
            mychar=myfile.get();
        }while(mychar!=';' && myfile.good());
    }

    mychar=myfile.get();

    bool endWhile = false;
    while(myfile.good() && !endWhile){
        if(std::string("0123456789;<").find(mychar) != std::string::npos)
            if(curmap!=10)
                endWhile=true;
            
        if(mychar=='\n')
            {j++; i=0; mychar=myfile.get();}
        else{
            Matrice[i][j]=mychar;
            i++;
            mychar=myfile.get();
        }
    }
    myfile.close();
}
