#include <iostream>
#include <time.h>
#include <curses.h>

#include "Engine.h"
#include "Potter.h"
#include "Malfoy.h"

using namespace std;

int main (int argc, char **argv)
{
    srand( (unsigned) time(0));

    Engine Engine;
    Engine.InsertMap(argv[1]);
    // for (int i=0; i< Engine.GetMap().size(); i++)
    // {
    //     cout << Engine.GetMap()[i] << endl;
    // }

    initscr();
    noecho();
    cbreak();

    printw("\n\n\n\n WELCOME \n\n\n PRESS ANY KEY TO CONTINUE\n\n");
    refresh();
    getch();
    clear();

    Engine.PrintwMap();
    refresh();
    getch();
    Engine.GetMove();
    




    endwin();


    return 0;
}