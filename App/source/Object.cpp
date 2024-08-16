#include "Object.h"

//_____________
/*
    Constructor Settings
*/

Object::Object()
{
    setBody();
}





//--------------
/*
    Main Object Settings
*/

void Object::Draw()
{
    if(textCase)
    {
        DrawText(text.c_str(), pos.x, pos.y, fontSize, color);
    }
    else
    {
        DrawRectangle(object.x, object.y, object.width, object.height, color);
    }
}
void Object::Update()
{
    setBody();
}

//-------------
/*
    Object Body Settings
*/

void Object::setBody()
{
    objectBody.bottom = object.y + object.height;
    objectBody.top = object.y;
    objectBody.left = object.x;
    objectBody.right = object.x + object.width;

    object.x = pos.x;
    object.y = pos.y;
    object.width = width;
    object.height = height;

}

//-------------