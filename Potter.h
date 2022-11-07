#ifndef Potter_h
#define Potter_h

#include <iostream>
#include "Player.h"

using namespace std;

class Potter: public Player
{
 public:
    Potter( vector <string> &);
    ~Potter();
    int GetMove();
};
#endif



