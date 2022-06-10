#include "Potter.h"

#define ESCAPE 27
#define SPACE 32
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68


 Potter::Potter(vector <string> & map): Player(map)
 {
    
 }
Potter::~Potter()
{

}

int Potter::GetMove()
{
    int choice;
    bool check=false;
    do
    {
        //choice = wgetch(stdscr);
        choice = getch();

        switch (choice)
        {
        case KEY_UP:
            check=MoveUp();
            break;
        case KEY_DOWN:
            check=MoveDown();
            break;
        case KEY_RIGHT:
           check=MoveRight();
            break;
        case KEY_LEFT:
            check=MoveLeft();
            break;
        case SPACE:
            check= StandStill();
            break;
        case ESCAPE:
            ExitGame();
            check=true;
            break;
        }
        
    } while (check== false);
    
    

   
    return choice;
}


