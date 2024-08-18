#pragma once

#include "Base.h"

struct Dim
{
    int width;
    int height;
};

struct Playerbody
{
    float top;
    float bottom;
    float left;
    float right;

    Vector2 pos;
    Dim scale;
};

class Player
{
public:
    Player();
    ~Player() = default;

    void Update();
    void Draw();

public:
    bool TopCollisionCheck = false;
    bool BottomCollisionCheck = false;
    bool LeftCollisionCheck = false;
    bool RightCollisionCheck = false;

    int ground;

    float gravity = 1.0f;
    Vector2 vel = {0, 0};
    float speed = 10.0f;

public:
    Color color = GREEN;

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
