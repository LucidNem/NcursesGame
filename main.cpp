#include <iostream>
#include <time.h>
#include <curses.h>
#include <stdio.h>      
#include <stdlib.h>     

#include "Engine.h"
#include "Potter.h"
#include "Malfoy.h"
#include "Diamond.h"

using namespace std;

int main (int argc, char **argv)
{
    srand( (unsigned) time(0));
    initscr();
    curs_set(0);
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    init_pair(3,COLOR_WHITE,COLOR_WHITE);
    init_pair(4,COLOR_BLUE,COLOR_BLACK);

    Engine Engine(argv[1]);
    Engine.StartGame();

     endwin();
    

    return 0;
}

