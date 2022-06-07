#include "Engine.h"
#include <string.h>
#include <string>


Engine::Engine()
{
    cout<<"Constructing Engine"<<endl;
}


Engine::~Engine()
{
    
}

void Engine::StartGame( char *MapFile)
{
    InsertMap(MapFile);
    Player Player(map);
        //Potter Potter(map);
    // Malfoy Malfoy(map);

    // pair <int,int> temp= Potter.StartPositions();
    // SetMap(temp.first,temp.second, 'M');

    // temp= Malfoy.StartPositions();
    // SetMap(temp.first,temp.second, 'L');

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
    //GetMove();
    

   

    endwin();
    //cout << strlen(map[1].c_str());

}

void Engine::StartPositions()
{

}

void Engine::SetMap(int y,int x, char letter)
{
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
        printw("%s\n",map[i].c_str());
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
