#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <time.h>
#include <curses.h>
#include <stdio.h>      
#include <stdlib.h>  


using namespace std;

class Player
{
protected:
    int y;
    int x;
    vector <string> map;
    


 public:
    Player( vector <string> );
    virtual ~Player();

    pair <int,int> StartPositions();
    int pick_y();
    int pick_x();

    int Gety() const;
    const int Getx() const;
    void Sety(int);
    void Setx(int);

    void GetMove();
    bool CheckMove(int,int);

    bool MoveUp();
    bool MoveDown();
    bool MoveRight();
    bool MoveLeft();
    bool StandStill();
    bool ExitGame();

    void UpdateMapFromEngine(vector <string>);

};

#endif