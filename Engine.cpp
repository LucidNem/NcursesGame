#include "Engine.h"
#include <string.h>
#include <string>


Engine::Engine(char * MapFile)
{
    InsertMap(MapFile);
    StartMap=map;
    charMap = new char * [map.size()];
    for (int i=0; i<map.size(); i++)
    {
        charMap[i] = new char [ strlen(map[1].c_str())];
    }
    
    for (int i=0; i<map.size(); i++)
    {
        for (int j=0; j< strlen(map[1].c_str()); j++)
        {
            charMap[i][j]= map[i][j];
        }
    }
}

Engine::~Engine()
{
    for (int i=0; i<map.size(); i++)
    {
        delete [] charMap[i];
    }
    delete [] charMap;
}



void Engine::StartGame( )
{
    Diamond Diamond(map);
    SetMap(Diamond.Gety(),Diamond.Getx(), 'D');
    Potter Potter(map);
    SetMap(Potter.Gety(),Potter.Getx(), 'M');
    Malfoy Malfoy(map);
    SetMap(Malfoy.Gety(),Malfoy.Getx(), 'L');

    initscr();
    noecho();
    cbreak();

    printw("\n\n\n\n WELCOME \n\n\n PRESS ANY KEY TO CONTINUE\n\n");
    refresh();
    getch();
    clear();

    PrintwMap();
    refresh();

    bool check=false;
    do
    {
        clear();
        PrintwMap();
        refresh();
        SetMap(Potter.Gety(),Potter.Getx(), ' ');
        Potter.GetMove();
        SetMap(Potter.Gety(),Potter.Getx(), 'M');
        check = CheckWin(Potter,Diamond);
        if (check==true)
        {
            break;
        }

        SetMap(Malfoy.Gety(),Malfoy.Getx(), ' ');
        Malfoy.GetMove();
        SetMap(Malfoy.Gety(),Malfoy.Getx(), 'L');
        check = CheckWin(Malfoy,Diamond);

    } while (check==false);
    


  

    endwin();

}


bool Engine::CheckWin(Player & Player, Diamond &Diamond)
{
    if ( Player.Gety() == Diamond.Gety()  &&  Player.Getx()==Diamond.Getx() )
    {
        return true;
    }
    return false;
}
    

void Engine::SetMap(int y,int x, char letter)
{
    charMap[y][x]=letter;
    map[y][x]=letter;
}

void Engine::InsertMap(char * MapFile)
{
    fstream File;
    string line;
    File.open(MapFile, ios::in);

    if (File.is_open())
    {
        while (getline (File, line))
        {
            map.push_back(line);
        }
        File.close();
    }
}

const vector <string> & Engine::GetMap() const
{
    return map;
}

void Engine::PrintwMap()
{
    for (int i=0; i< map.size(); i++)
    {
        for (int j=0; j< strlen(map[1].c_str()) ; j++)
        {
            printw("%c", charMap[i][j]);
        }
        printw("\n");

       //printw("%s\n",map[i].c_str());
    }
}
    
int Engine::pick_y()
{
    int y;
    y = (rand() % map.size()) ;
    return y;
}   
   

int Engine::pick_x()
{
    int x;
     int chars_per_line= strlen(map[1].c_str());
    x = (rand() % chars_per_line ) ;
    return x;
}


bool Engine::CheckMove(int x, int y)
{   
    return true;
}
