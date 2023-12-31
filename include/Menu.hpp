#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include <ncurses.h>
#include <string>
#include "Mappa.hpp"

class Menu
{
private:
    WINDOW *menuwin;
    WINDOW *inputwin;
    Mappa *map;

public:
    Menu(WINDOW *menuwin, WINDOW *inputwin);
    void titolo();
    void GameOver();
    int finestraMenu();
    void finestraGioco();
};
#endif