#include "Base.h"
#include "Window.h"

Window::Window(int width, int height, std::string& title)
{
    Open(width, height, title);
}

void Window::Open(int width, int height, std::string& title)
{
    SetTargetFPS(60);
    InitWindow(width, height, title.c_str());
}
void Window::Close()
{
    CloseWindow();
}
