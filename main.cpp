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

    Engine Engine(argv[1]);
    Engine.StartGame();
    
    return 0;
}

