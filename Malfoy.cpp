#include "Malfoy.h"
#include "Diamond.h"

#define ESCAPE 27
#define SPACE 32
#include <iostream>

using namespace std;

 Malfoy::Malfoy(vector <string> & map):Player(map)
 {

 }
Malfoy::~Malfoy()
{

}


int Malfoy::GetMove()
{
    int choice=1;
    bool check=false;
    
    FindRouteMap[this->y][this->x]=0;

    for (int i=0;i<map.size(); i++)
    {
        for (int j=0; j<strlen(map[0].c_str()); j++)
        {
            if (map[i][j]=='*')
            {
                FindRouteMap[i][j] = -1;
            }
            else if ( map[i][j]== ' ')
            {
                FindRouteMap[i][j]=-2;
            }
            else if ( map[i][j]== 'D')
            {
                Dy=i;
                Dx=j;   
                FindRouteMap[i][j]=-3;
            }
        }
    }


    int i=1;
    int j=2;

    do
    {
        
        int tempy,tempx;
        tempy= this->y;
        tempx= this->x;
        FindRoute(tempy,tempx); // εδώ στέλνω το 0 δηλαδή τη θέση του Malfoy
    
        tempy= tempy-i;
        FindRoute(tempy,tempx);
        tempy= tempy+j;
        FindRoute(tempy,tempx);
        tempx= tempx-i;
        FindRoute(tempy,tempx);
        tempx= tempx+j;
        FindRoute(tempy,tempx);

        j=j+1;
        i=i+1;
    
       
    } while ( FindRouteMap[Dy-1] [Dx] < 0 || FindRouteMap[Dy+1] [Dx] < 0 || FindRouteMap[Dy] [Dx-1] <0 || FindRouteMap[Dy] [Dx+1] < 0 );


    for (int i=0; i<FindRouteMap.size(); i++)
    {
        for (int j=0; j<FindRouteMap[0].size(); j++)
        {
            cout<< FindRouteMap[i][j];
        }
        cout << endl;
    }
    
    
    return choice;
}





 void Malfoy::FindRoute(int y, int x)
{
    if ( y>0 && y < FindRouteMap.size() && x>0 && x< FindRouteMap[0].size() )
    {
        if ( FindRouteMap[y][x]!= -1)
        {
            if (FindRouteMap[y-1][x] == -2)
            {
                FindRouteMap[y-1][x] = FindRouteMap[y][x]+1;
            }
            
        
            if( FindRouteMap[y+1][x] == -2)
            {
                FindRouteMap[y+1][x] =FindRouteMap[y][x]+1;
            }
           

            if( FindRouteMap[y][x-1] == -2)
            {
                FindRouteMap[y][x-1] =FindRouteMap[y][x]+1;
            }
            

            if( FindRouteMap[y][x+1] == -2)
            {
                FindRouteMap[y][x+1] =FindRouteMap[y][x]+1;
            }
           
        }
    }
   
        
}