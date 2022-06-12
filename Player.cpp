#include "Player.h"
#include <string>
#include <cstring>
#define ESCAPE 27
#define SPACE 32

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
        if (map[tempy][tempx] != '*' && map[tempy][tempx] != 'M' && map[tempy][tempx] != 'L' && map[tempy][tempx] != 'D')
        {
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

void Player::UpdateMapFromEngine(vector <string> & xmap)
{
    this->map=xmap;
}


void Player::GetMove()
{

}

bool Player::CheckMove(int y,int x)
{   
    if (map[y][x] != '*')
    {
        return true;
    }
    return false;
}


bool Player::MoveUp()
{
    int tempy=y-1;
    int tempx=x;
    if (CheckMove(tempy, tempx)==true)
    {
        this->y = tempy;
        return true;
    }
    return false;
}

bool Player::MoveDown()
{
    int tempy=y+1;
    int tempx=x;
    if (CheckMove(tempy, tempx)==true)
    {
        this->y = tempy;
        return true;
    }
    return false;
}

bool Player::MoveRight()
{
    int tempy=y;
    int tempx=x+1;
    if (CheckMove(tempy, tempx)==true)
    {
        this->x = tempx;
        return true;
    }
    return false;
}

bool Player::MoveLeft()
{
    int tempy=y;
    int tempx=x-1;
    if (CheckMove(tempy, tempx)==true)
    {
        this->x = tempx;
        return true;
    }
    return false;
}

bool Player::StandStill()
{
    return true;
}

bool Player::ExitGame()
{
   return true;
}
