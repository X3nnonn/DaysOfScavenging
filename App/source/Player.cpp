#include "Player.h"



Player::Player()
{
    setBody();
}


//_____________
/*
    Main Player Settings
*/

void Player::Draw()
{
    DrawRectangle(bodyDim.x, bodyDim.y, bodyDim.width, bodyDim.height, color);
}
void Player::Update()
{
    setBody(); /* Log Player Collision Check */   printf("T L R B: "); printf("%d, %d, %d, %d\n", TopCollisionCheck, LeftCollisionCheck, RightCollisionCheck, BottomCollisionCheck);

    moveDir();    /* Log Player Position */   //printf("Player Positon: "); printf(V2_FMT, V2_OPEN(pos));
    pos.x += vel.x;

    moveFall();

    moveJump();
    pos.y += vel.y;

    
}

//-------------
/*
    Body and Movement/Collison Settings
*/ 

void Player::setBody()
{
    body.top = pos.y; body.bottom = pos.y + bodyDim.height;
    body.left = pos.x; body.right = pos.x + bodyDim.width;

    bodyDim.x = pos.x; bodyDim.y = pos.y;
    bodyDim.width = bodyDim.width; bodyDim.height = bodyDim.height;

}

void Player::moveDir()
{
    if ( LeftCollisionCheck ) {
        if ( IsKeyDown(KEY_D) ) direction = 1;
    }
    else if (RightCollisionCheck ) { 
        if ( IsKeyDown(KEY_A) ) direction = -1; 
    }
    else { direction = IsKeyDown(KEY_D) - IsKeyDown(KEY_A); }

    vel.x = speed*direction;
}
void Player::moveJump()
{
    if(IsKeyPressed(KEY_W))
    {
        if(vel.y == 0)
        {
            vel.y = -30;
        }
    }
}
void Player::moveFall()
{
    if(body.bottom < ground) { BottomCollisionCheck = false;
        vel.y += gravity;

    }else { BottomCollisionCheck = true;
        vel.y = 0;
        pos.y = ground - bodyDim.height;

    }
}

