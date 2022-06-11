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
            if (map[i][j]=='*')
            {
                FindRouteMap[i][j] = -1;
            }
            else if ( map[i][j]== ' ' || map[i][j]== 'M')
            {
                FindRouteMap[i][j] = -2;
            }
            else if ( map[i][j] == 'D')
            {
                Dy=i;
                Dx=j;   
                FindRouteMap[i][j]=-3;
            }
        }
    }
     FindRouteMap[this->y][this->x]=0;


    int i=0;
    int j=2;
 
    int tempy,tempx;
    tempy= this->y;
    tempx= this->x;
    FindRoute(tempy,tempx); // εδώ στέλνω το 0 δηλαδή τη θέση του Malfoy
    do
    {
        // tempy= tempy-i;
        // FindRoute(tempy,tempx);
        // tempy= tempy+j;
        // FindRoute(tempy,tempx);
        // tempy=tempy-j+i;

        // tempx= tempx-i;
        // FindRoute(tempy,tempx);
        // tempx= tempx+j;
        // FindRoute(tempy,tempx);
        // tempx=tempx-j+i;

        // j=j+1;
         
    
        PassNums(i);
        i=i+1;
       
    } while ( FindRouteMap[Dy-1][Dx] < 0 && FindRouteMap[Dy+1][Dx] < 0 && FindRouteMap[Dy][Dx-1] <0 && FindRouteMap[Dy][Dx+1] < 0 );


    for (int i=0; i<map.size(); i++)
    {
        for (int j=0; j<map[0].size(); j++)
        {
            cout<< FindRouteMap[i][j];
        }
        cout << endl;
    }

    
    return choice;
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