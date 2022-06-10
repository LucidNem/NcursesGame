#ifndef Malfoy_h
#define Malfoy_h

#include <iostream>
#include "Player.h"

using namespace std;

class Malfoy: public Player
{
 private:

 public:
    Malfoy( vector <string> &);
    ~Malfoy();
    int GetMove();

    pair <int,int> StartPositions();

};

#endif