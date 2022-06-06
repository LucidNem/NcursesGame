#include "Malfoy.h"

 Malfoy::Malfoy(const vector <string> & map):Player(map)
 {
    cout<< "Mphke malfoy " <<endl;
 }
Malfoy::~Malfoy()
{

}

pair <int,int> Malfoy::StartPositions()
{ 
    int i,tempy,tempx,check;
   
    tempy= pick_y();
    tempx= pick_x();
    check=0;
    
    do
    {
       // if (( map[y][x] != '*' ) && (map[y][x] !='') )
        if (map[y][x]== ' ')
        {
            map[y][x]= 'L';
            check =1;
            this->y=tempy;
            this->x=tempx;
        }
        else
        {
            this->y= pick_y();
            this->x= pick_x();
        }
    }
    while (check==0);

    pair <int,int> cords (y,x);
    return cords;
}