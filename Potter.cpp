#include "Potter.h"


 Potter::Potter(vector <string> & map): Player(map)
 {
     cout<<"mphke potter" <<endl;
 }
Potter::~Potter()
{

}

pair <int,int> Potter::StartPositions()
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
            map[y][x]= 'M';
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