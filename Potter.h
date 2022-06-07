#ifndef Potter_h
#define Potter_h

#include <iostream>
#include "Player.h"

using namespace std;

class Potter: public Player
{
 //private:

 public:
    Potter( vector <string> &);
    ~Potter();

    pair <int,int> StartPositions();

};

#endif



