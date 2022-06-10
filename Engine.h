#ifndef Engine_h
#define Engine_h

#include <iostream>
#include <vector>
#include <curses.h>
#include <fstream>
#include <string>

#include "Player.h"
#include "Potter.h"
#include "Malfoy.h"
#include "Diamond.h"

using namespace std;

class Engine
{
private:
    vector <string> map;
    vector <string> StartMap;
    char ** charMap;

public:
    Engine(char *);
    ~Engine();

    void StartGame();
    void InsertMap(char *);
    const vector <string> & GetMap() const;

    int pick_y();
    int pick_x();

    void SetMap(int,int, char);
    bool CheckWin(Player &, Diamond &);

    void PrintwMap();
    bool CheckMove(int,int);

};

#endif