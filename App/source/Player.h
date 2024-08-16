#pragma once

#include "Base.h"


struct Playerbody
{
    float top;                
    float bottom;                
    float left;            
    float right;           
};


class Player
{
public: 
    Player(); ~Player() = default;

    void Update();
    void Draw();

    

public:
    bool TopCollisionCheck = false; bool BottomCollisionCheck = false; bool LeftCollisionCheck = false; bool RightCollisionCheck = false;
    
    int ground;
    
    float gravity = 1.0f;
    Vector2 vel = {0, 0};
    float speed = 10.0f;

    

public:
    Rectangle bodyDim;
    Color color;
    Vector2 pos = {DefWinWidth/2, DefWinHeight/2};

    Playerbody body;

private:
    void setBody();

    void moveDir();
    void moveJump();
    void moveFall();



private:
    float direction = 0;

    

private:
    
    
};


