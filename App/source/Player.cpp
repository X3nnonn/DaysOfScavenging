#include "Player.h"
#include "raylib.h"

Player::Player()
{
    setBody();
    body.scale.width = 48;
    body.scale.height = 56;
}

//_____________
/*
    Main Player Settings
*/

void Player::Draw()
{
    Rectangle rect = {body.pos.x, body.pos.y, (float)body.scale.width, (float)body.scale.height};
    DrawRectangleLinesEx(rect, 4, color);
}

void Player::Update()
{
    setBody(); /* Log Player Collision Check */

    moveDir(); /* Log Player Position */ // printf("Player Positon: "); printf(V2_FMT, V2_OPEN(pos));
    body.pos.x += vel.x;

    moveFall();

    moveJump();
    body.pos.y += vel.y;
    setBody(); /* Log Player Collision Check */
    /*
    printf("T L R B: ");
    printf("%d, %d, %d, %d\n", TopCollisionCheck, LeftCollisionCheck, RightCollisionCheck, BottomCollisionCheck);*/
}

//-------------
/*
    Body and Movement/Collison Settings
*/

void Player::setBody()
{
    ground = DEFAULT_WINDOW_HEIGHT * 0.8f;

    body.top = body.pos.y;
    body.bottom = body.pos.y + body.scale.height;
    body.left = body.pos.x;
    body.right = body.pos.x + body.scale.width;

    body.pos.x = body.pos.x + 39;
    body.pos.y = body.pos.y + 32;
    body.scale.width = body.scale.width;
    body.scale.height = body.scale.height;
}

void Player::moveDir()
{
    if (LeftCollisionCheck)
    {
        if (IsKeyDown(KEY_D))
            direction = 1;
    }
    else if (RightCollisionCheck)
    {
        if (IsKeyDown(KEY_A))
            direction = -1;
    }
    else
    {
        direction = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    }

    vel.x = speed * direction;
}
void Player::moveJump()
{
    if (IsKeyPressed(KEY_W))
    {
        if (vel.y == 0)
        {
            vel.y = -30;
        }
    }
}
void Player::moveFall()
{
    if (body.bottom < ground)
    {
        BottomCollisionCheck = false;
        vel.y += gravity;
    }
    else
    {
        BottomCollisionCheck = true;
        vel.y = 0;
        body.pos.y = ground - body.scale.height;
    }
}
