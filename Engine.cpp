#include "Engine.h"


Engine::Engine()
{
    cout<<"Constructing Engine"<<endl;
}


Engine::~Engine()
{
    
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
    
void Engine::StartPositions()
{

}


bool Engine::MoveUp()
{

}
bool Engine::MoveDown()
{

}
bool Engine::MoveRight()
{

}
bool Engine::MoveLeft()
{
    
}
bool Engine::StandStill()
{

}
bool Engine::ExitGame()
{

}

bool Engine::CheckMoveValid()
{

}





