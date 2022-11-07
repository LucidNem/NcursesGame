

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
            FindRouteMap[i][j]= 0;
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
    bool check=false;

    for (int i=0;i<map.size(); i++)
    {
        for (int j=0; j<strlen(map[0].c_str()); j++)
        {
           
            if ( map[i][j] == 'D')
            {
                Dy=i;
                Dx=j;   
                FindRouteMap[i][j] = 1;
            }
        }
    }


    int counter=2;
    
    FindRoute(Dy,Dx); 
    do
    {
        PassNums(counter);
        counter=counter+1;
       
    } while ( FindRouteMap[Dy-1][Dx] < 0 && FindRouteMap[Dy+1][Dx] < 0 && FindRouteMap[Dy][Dx-1] < 0 && FindRouteMap[Dy][Dx+1] < 0 );

    desty= Dy;
    destx =Dx;

    if (FindRouteMap[desty-1][destx]>0)
    {
        desty=Dy-1;
        destx=Dx;

    }
    else if (FindRouteMap[desty+1][destx] >0)
    {
        desty=Dy+1;
        destx=Dx;
    }
    else if (FindRouteMap[desty][destx-1] >0)
    {
        desty=Dy;
        destx=Dx-1;
    }
    else if (FindRouteMap[desty][destx+1] >0)
    {
        desty=Dy;
        destx=Dx+1;
    }
    
    for (int i=0; i<map.size(); i++)
    {
        for (int j=0; j<map[i].size(); j++)
        {
            printw("%d", FindRouteMap[i][j]);
        }
        printw("\n");
    }
    refresh();

    do
    {
        FinalDestination();
        //cout <<" vriskei to route" << endl;
    } while (FindRouteMap[desty][destx]!=1);
    
    this->y=desty;
    this->x=destx;
    
    return choice;
}

void Malfoy::FinalDestination ()
{
    if (FindRouteMap[desty-1][destx] == FindRouteMap[desty][destx] -1 )
    {
        desty=Dy-1;
        destx=Dx;

    }
    else if (FindRouteMap[desty+1][destx] == FindRouteMap[desty][destx]-1)
    {
        desty=Dy+1;
        destx=Dx;
    }
    else if (FindRouteMap[desty][destx-1] ==FindRouteMap[desty][destx] - 1)
    {
        desty=Dy;
        destx=Dx-1;
    }
    else if (FindRouteMap[desty][destx+1] == FindRouteMap[desty][destx] -1)
    {
        desty=Dy;
        destx=Dx+1;
    }
}




void Malfoy::PassNums(int given)
{
    for (int i=0; i<map.size(); i++)
    {
        for (int j=0; j < strlen(map[0].c_str()); j++)
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
    if ( y>0 && y < map.size() && x>0 && x< map[0].size() )
    {
        if ( map[y][x]!= '*')
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