#pragma once

#include "Window.h"


struct AppInfo
{
    Vector2 WinSize;
    std::string title;
};

class Application
{
public:
    Application(AppInfo& info); ~Application();

    void Run();
    void Quit();

    void HandleEvents();

    virtual void OnUpdate();
    virtual void OnRender();
    virtual void OnRenderUI();

public:

private:
    
private:
    AppInfo m_info;

    Window m_window;

    bool m_isRunning = true;
};