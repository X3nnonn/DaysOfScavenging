#pragma once

#include "Base.h"

class Window
{
public:
    Window() = default;
    Window(int width, int height, std::string& title);
    ~Window() = default;

    void Open(int width, int height, std::string& title);
    void Close();

public:
private:
private:
};
