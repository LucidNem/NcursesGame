#ifndef Malfoy_h
#define Malfoy_h

#include <iostream>
#include "Player.h"
#include "Diamond.h"

using namespace std;

class Malfoy: public Player
{
 private:
     //vector <vector <int> > FindRouteMap;
     int Dy;
     int Dx;
     int desty;
     int destx;
     int ** FindRouteMap;

 public:
    Malfoy( vector <string> &);
    ~Malfoy();
    int GetMove();
    void PassNums(int);
    void FinalDestination();

    pair <int,int> StartPositions();
    void FindRoute(int, int);


};

#endif