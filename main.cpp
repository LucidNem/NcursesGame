#include <iostream>
#include <time.h>
#include <curses.h>
#include <stdio.h>      
#include <stdlib.h>     

#include "Engine.h"
#include "Potter.h"
#include "Malfoy.h"

using namespace std;

int main (int argc, char **argv)
{
    srand( (unsigned) time(0));

    Engine Engine;
    Engine.StartGame(argv[1]);
    

    return 0;
}