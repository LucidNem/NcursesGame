#ifndef Engine_h
#define Engine_h

#include <iostream>
#include <vector>
#include <curses.h>
#include <fstream>
#include <string>

#include "Potter.h"
#include "Malfoy.h"
//#include "Diamond"

using namespace std;

class Engine
{
private:
    vector <string> map;

public:
    Engine();
    ~Engine();

    void StartGame(char *);
    void InsertMap(char *);
    const vector <string> & GetMap() const;

    int pick_y();
    int pick_x();

    void SetMap(int,int, char);

    int GetMove();
    void PrintwMap();
    void StartPositions();
    bool MoveUp();
    bool MoveDown();
    bool MoveRight();
    bool MoveLeft();
    bool StandStill();
    bool ExitGame();
    bool CheckMoveValid();

};

#endif