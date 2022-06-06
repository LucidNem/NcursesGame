#include "Player.h"

Player::Player( const vector <string> & map)
{
    this->map= map;
    StartPositions();
    cout << "mphke player" << endl;

}


Player::~Player()
{

}

pair <int,int> Player::StartPositions()
{ 
    int i,tempy,tempx,check;
   
    tempy= pick_y();
    tempx= pick_x();
    check=0;
      
    do
    {
       // if (( map[y][x] != '*' ) && (map[y][x] !='') )
        if (map[y][x]== ' ')
        {
            map[y][x]= 'M';
            check =1;
            this->y=tempy;
            this->x=tempx;
        }
        else
        {
            this->y= pick_y();
            this->x= pick_x();
        }
    }
    while (check==0);

    pair <int,int> cords (y,x);
    return cords;
}



int Player::pick_y()
{
    int y;
    y = (rand() % map.size()) ;
    return y;
}   
   

int Player::pick_x()
{
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
