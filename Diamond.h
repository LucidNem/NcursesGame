#ifndef Diamond_h
#define Diamond_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Diamond
{
private:
    int y;
    int x;
    vector <string> map;

public:
    Diamond(vector <string>);
    ~Diamond();

    const int Gety() const;
    const int Getx() const;
    void Sety(int);
    void Setx(int);

    int pick_y();
    int pick_x();

    pair <int,int> StartPositions();
    void ChangePos();

};



#endif