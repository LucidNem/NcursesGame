#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Player
{
protected:
    int y;
    int x;
    vector <string> map;


 public:
    Player(const vector <string> &);
    virtual ~Player();

    pair <int,int> StartPositions();
    int pick_y();
    int pick_x();

    void GetMove();
    bool CheckMove(int, int);
    void DoMove();

    int Gety() const;
    const int Getx() const;
    void Sety(int);
    void Setx(int);

};

#endif