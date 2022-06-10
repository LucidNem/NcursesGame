#include "Engine.h"
#include <string.h>
#include <string>


Engine::Engine(char * MapFile)
{
    InsertMap(MapFile);
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
    Potter Potter(map);
    SetMap(Potter.Gety(),Potter.Getx(), 'M');
    Malfoy Malfoy(map);
    SetMap(Malfoy.Gety(),Malfoy.Getx(), 'L');

    // for(int i=0; i< map.size(); i++)
    // {
    //     cout << map[i] << endl;
    // }

    initscr();
    noecho();
    cbreak();

    printw("\n\n\n\n WELCOME \n\n\n PRESS ANY KEY TO CONTINUE\n\n");
    refresh();
    getch();
    clear();

    PrintwMap();
    refresh();
    getch();
    
  
   

    endwin();
    //cout << strlen(map[1].c_str());

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
/*
 int Engine::GetMove()
{
    int choice = wgetch(stdscr);

    switch (choice)
    {
        case KEY_UP:
            MoveUp();
            break;
        case KEY_DOWN:
            MoveDown();
            break;
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_LEFT:
            MoveLeft();
            break;
        case SPACE:
            StandStill();
            break;
        case ESCAPE():
            ExitGame();
            break;
    }
    return choice;
}
*/
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
    



// bool Engine::MoveUp()
// {

//     //if ( CheckMoveValid()==true)
//     {

//     }

// }
// bool Engine::MoveDown()
// {

// }
// bool Engine::MoveRight()
// {

// }
// bool Engine::MoveLeft()
// {
    
// }
// bool Engine::StandStill()
// {

// }
// bool Engine::ExitGame()
// {

// }

// bool Engine::CheckMoveValid()
// {

// }



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
