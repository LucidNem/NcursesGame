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
    Engine.StartGame(argv[1]);
    
   // Engine.InsertMap(argv[1]);
    // for (int i=0; i< Engine.GetMap().size(); i++)
    // {
    //     cout << Engine.GetMap()[i] << endl;
    // }

    

    return 0;
}