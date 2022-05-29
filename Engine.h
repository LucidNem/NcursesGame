#ifndef Engine_h
#define Engine_h

#include <iostream>
#include <vector>
#include <curses.h>
#include <fstream>
#include <string>

using namespace std;

class Engine
{
private:
    vector <string> map;

public:
    Engine();
    ~Engine();

    void InsertMap(char *);
    const vector <string> & GetMap() const;

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