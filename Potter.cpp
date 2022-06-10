#include "Potter.h"


 Potter::Potter(vector <string> & map): Player(map)
 {
    
 }
Potter::~Potter()
{

}

// pair <int,int> Potter::StartPositions()
// { 
//    int i,tempy,tempx,check;
//     srand( (unsigned) time(0));
   
//     tempy= pick_y();
//     tempx= pick_x();
//     check=0;
      
//     do
//     {
//         //if (map[tempy][tempx] ==' ') 
//         if (map[tempy][tempx] != '*' && map[tempy][tempx]!='M' && map[tempy][tempx] != 'L' && map[tempy][tempx] != 'D')
//         {
//             //map[tempy][tempx] = 'M';
//             check =1;
//             this->y=tempy;
//             this->x=tempx;
//         }
//         else
//         {
//             tempy= pick_y();
//             tempx= pick_x();
//         }
//     }
//     while (check==0);

//     pair <int,int> cords (y,x);
//     return cords;
// }