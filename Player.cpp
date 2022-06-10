#include "Player.h"
#include <string>

Player::Player( vector <string>  xmap)
{
    this->map= xmap;
    StartPositions();
}


Player::~Player()
{

}

pair <int,int> Player::StartPositions()
{ 
    int i,tempy,tempx,check;
    srand( (unsigned) time(0));
   
    tempy= pick_y();
    tempx= pick_x();
    check=0;
      
    do
    {
        //if (map[tempy][tempx] ==' ') 
        if (map[tempy][tempx] != '*' && map[tempy][tempx] != 'M' && map[tempy][tempx] != 'L' && map[tempy][tempx] != 'D')
        {
            //map[tempy][tempx] = ' ';
            check =1;
            this->y=tempy;
            this->x=tempx;
        }
        else
        {
            tempy= pick_y();
            tempx= pick_x();
        }
    }
    while (check==0);

    pair <int,int> cords (y,x);
    return cords;
}



int Player::pick_y()
{
    srand( (unsigned) time(0));
    int y;
    y = (rand() % map.size()) ;
    return y;
}   
   

int Player::pick_x()
{
    srand( (unsigned) time(0));
    int x;
     int chars_per_line= strlen(map[1].c_str());
    x = (rand() % chars_per_line ) ;
    return x;
}


int Player::Gety() const
{
    return y;
}

const int Player::Getx() const
{
    return x;
}

void Player::Sety(int y)
{
    this->y = y;
}

void Player::Setx(int x)
{
    this->x = x;
}


void Player::GetMove()
{

}

bool Player::CheckMove(int x, int y)
{   
    return true;
}
void Player::DoMove()
{

}
