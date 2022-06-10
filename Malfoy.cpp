#include "Malfoy.h"

#define ESCAPE 27
#define SPACE 32

 Malfoy::Malfoy(vector <string> & map):Player(map)
 {

 }
Malfoy::~Malfoy()
{

}


int Malfoy::GetMove()
{
    int choice;
    bool check=false;
    do
    {
        srand(time(NULL));
        choice = (rand() % 4);

        switch (choice)
        {
        case 0:
            check=MoveUp();
            break;
        case 1:
            check=MoveDown();
            break;
        case 2:
           check=MoveRight();
            break;
        case 3:
            check=MoveLeft();
            break;
        
        }
        
    } while (check== false);
    
    

   
    return choice;
}