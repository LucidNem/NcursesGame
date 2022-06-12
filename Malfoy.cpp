#include "Malfoy.h"
#include "Diamond.h"

#define ESCAPE 27
#define SPACE 32
#include <iostream>

using namespace std;

 Malfoy::Malfoy(vector <string> & map):Player(map)
 {
    FindRouteMap = new int * [map.size()];
    for (int i=0; i<map.size(); i++)
    {
        FindRouteMap[i] = new int [ strlen(map[1].c_str())];
    }
    
    for (int i=0; i<map.size(); i++)
    {
        for (int j=0; j< strlen(map[1].c_str()); j++)
        {
            if ( map[i][j] == 'D')
            {
                Dy=i;
                Dx=j;   
                FindRouteMap[i][j] = 1;
            }
            else 
            {
                FindRouteMap[i][j]= 0;
            }
            
        }
    }
 }
Malfoy::~Malfoy()
{
    for (int i=0; i<map.size(); i++)
    {
        delete [] FindRouteMap[i];
    }
    delete [] FindRouteMap;

}


int Malfoy::GetMove()
{
    int choice=1;
    int counter=2;
    FindRoute(Dy,Dx);
    while ( FindRouteMap[y][x]==0)
    {
        PassNums(counter);
        counter=counter+1; 
    }

    if (FindRouteMap[y-1][x] == FindRouteMap[y][x]-1)
    {
        y=y-1;
        x=x;

    }
    else if (FindRouteMap[y+1][x] == FindRouteMap[y][x]-1)
    {
        y=y+1;
        x=x;
    }
    else if (FindRouteMap[y][x-1] == FindRouteMap[y][x]-1)
    {
        y=y;
        x=x-1;
    }
    else if (FindRouteMap[y][x+1] == FindRouteMap[y][x]-1)
    {
        y=y;
        x=x+1;
    }
    
     return choice;

}



void Malfoy::PassNums(int given)
{
    for (int i=1; i<map.size(); i++)
    {
        for (int j=1; j < strlen(map[0].c_str()); j++)
        {
            if (FindRouteMap[i][j]==given )
            {
                FindRoute(i,j);

            }
        }
    }
}


 void Malfoy::FindRoute(int y, int x)
{
    if ( y>0 && y < map.size()-1 && x>0 && x< map[0].size()-1 )
    {
        if ( map[y][x]!= '*')
        {
            if ( (FindRouteMap[y-1][x] == 0) && (map[y-1][x] != '*'))
            {
                FindRouteMap[y-1][x] = FindRouteMap[y][x]+1;
            }
            
        
            if( (FindRouteMap[y+1][x] == 0) && (map[y+1][x] != '*'))
            {
                FindRouteMap[y+1][x] =FindRouteMap[y][x]+1;
            }
           

            if( (FindRouteMap[y][x-1] == 0) && (map[y][x-1] != '*'))
            {
                FindRouteMap[y][x-1] =FindRouteMap[y][x]+1;
            }
            

            if( (FindRouteMap[y][x+1] == 0) && (map[y][x+1] != '*'))
            {
                FindRouteMap[y][x+1] =FindRouteMap[y][x]+1;
            }
           
        }
    }
   
        
}