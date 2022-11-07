#include "Diamond.h"
#include <cstring>

 Diamond::Diamond(vector <string> xmap)
 {
    this->map =xmap;
    StartPositions();
 }

Diamond::~Diamond()
{

}

const int Diamond::Gety() const
{
    return y;
}

const int Diamond::Getx() const
{
    return x;
}

void Diamond::Sety(int y)
{
    this->y = y;
}

void Diamond::Setx(int x)
{
    this->x = x;
}

pair <int,int> Diamond::StartPositions()
{ 
    int i,tempy,tempx,check;
    srand( (unsigned) time(0));
   
    tempy= pick_y();
    tempx= pick_x();
    check=0;
      
    do
    {
        if (map[tempy][tempx] != '*' && map[tempy][tempx] != 'M' && map[tempy][tempx] != 'L' && map[tempy][tempx] != 'D')
        {
            check =1;
            this->y=tempy;
            this->x=tempx;
        }
        else
        {
            tempy= pick_y();
            tempx= pick_x();
        }
    }
    while (check==0);

    pair <int,int> cords (y,x);
    return cords;
}

void Diamond::ChangePos()
{
    if ((rand() % 20) == (rand() % 20))
    {
        StartPositions();
    }
}

int Diamond::pick_y()
{
    srand( (unsigned) time(0));
    int y;
    y = (rand() % map.size()) ;
    return y;
}   
   
int Diamond::pick_x()
{
    srand( (unsigned) time(0));
    int x;
     int chars_per_line= strlen(map[1].c_str());
    x = (rand() % chars_per_line ) ;
    return x;
}