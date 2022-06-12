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

    curs_set(0);
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    init_pair(3,COLOR_WHITE,COLOR_WHITE);
    init_pair(4,COLOR_BLUE,COLOR_BLACK);
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
        refresh();
        PrintwMap();
        PrintPlayers(Potter,Malfoy,Diamond);  
        refresh(); 
        
        SetMap(Potter.Gety(),Potter.Getx(), ' ');
        SetMap(Malfoy.Gety(),Malfoy.Getx(), 'L');
        Potter.GetMove();
        SetMap(Potter.Gety(),Potter.Getx(), 'M');
        check = CheckWinPotter(Potter,Diamond);
        if (check==true)
        {
            break;
        }
        Malfoy.UpdateMapFromEngine(map);
        SetMap(Malfoy.Gety(),Malfoy.Getx(), ' ');
        SetMap(Potter.Gety(),Potter.Getx(), 'M');
        Malfoy.GetMove();
        SetMap(Malfoy.Gety(),Malfoy.Getx(), 'L');
        check = CheckWinMalfoy(Malfoy,Diamond);

        if (check==false)
        {
            SetMap(Diamond.Gety(),Diamond.Getx(), ' ');
            Diamond.ChangePos();
            SetMap(Diamond.Gety(),Diamond.Getx(), 'D');
        }

    } while (check==false);

    clear();
    refresh();

    if (CheckWinPotter(Potter,Diamond))
    {
        printw("\n\n\n\n\n\n\n\nCongratulations, You Won!!!");
    }
    else 
    {
        printw("\n\n\n\n\n\n\n\nSorry, You Lost!");
    }
    
    refresh();
    
    getch();
    getch();
    endwin();
}


bool Engine::CheckWinPotter(Player & Player, Diamond &Diamond)
{
    if ( Player.Gety() == Diamond.Gety()  &&  Player.Getx()==Diamond.Getx() )
    {
        return true;
    }
    return false;
}

bool Engine::CheckWinMalfoy(Player & Player, Diamond &Diamond)
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
    int j=0;
    for (int i=0; i< map.size(); i++)
    {
        for ( j=0; j< strlen(map[1].c_str()) ; j++)
        {
            if (map[i][j]== '*')
            {
                wattron(stdscr,COLOR_PAIR(3));
                mvwprintw(stdscr,i,j," ");
                wattroff (stdscr,COLOR_PAIR(3));
            }
            else //if (map[i][j] == '.')
            {
               mvwprintw(stdscr,i,j," ");
            }
            // else if (map[i][j] == 'D')
            // {
            //     wattron(stdscr,COLOR_PAIR(4));
            //     mvwprintw(stdscr,i,j,"$");
            //     wattroff (stdscr,COLOR_PAIR(4));
            // }
            // else if (map[i][j]== 'M')
            // {
            //     wattron(stdscr,COLOR_PAIR(1));
            //     mvwprintw(stdscr,i,j,"M");
            //     wattroff (stdscr,COLOR_PAIR(1));
            // }
            // else if (map[i][j]=='L')
            // {
            //     wattron(stdscr,COLOR_PAIR(2));
            //     mvwprintw(stdscr,i,j,"L");
            //     wattroff (stdscr,COLOR_PAIR(2));
            // }
            
        }
        mvwprintw(stdscr,i,j,"\n");
    }
    refresh();
}
    

void Engine::PrintPlayers(Potter & Potter, Malfoy & Malfoy, Diamond & Diamond)
{    
    wattron(stdscr,COLOR_PAIR(4));
    mvwprintw(stdscr,Diamond.Gety(),Diamond.Getx(),"$");
    wattroff (stdscr,COLOR_PAIR(4));
            
    if (Potter.Gety()== Malfoy.Gety() && Potter.Getx()==Malfoy.Getx())
    {
        wattron(stdscr,COLOR_PAIR(4));
        mvwprintw(stdscr,Potter.Gety(),Potter.Getx(),"+");
        wattroff (stdscr,COLOR_PAIR(4));
    }
    else
    {
        wattron(stdscr,COLOR_PAIR(1));
        mvwprintw(stdscr,Potter.Gety(),Potter.Getx(),"M");
        wattroff (stdscr,COLOR_PAIR(1));
           
        wattron(stdscr,COLOR_PAIR(2));
        mvwprintw(stdscr,Malfoy.Gety(),Malfoy.Getx(),"L");
        wattroff (stdscr,COLOR_PAIR(2));
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
