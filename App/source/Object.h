#pragma once

#include "Base.h"


struct SetObjectBody
{

    float top;                
    float bottom;                
    float left;            
    float right;           
};

class Object
{
public:
    Object();
    ~Object() = default;

    void Draw();
    void Update();

    void setBody();

public:
    Rectangle object;
    SetObjectBody objectBody;

    bool textCase = false;
    std::string text;
    int width;
    int height;
    Color color = PURPLE;
    int fontSize = 5;

    Vector2 pos = {0};

private:

private:
};