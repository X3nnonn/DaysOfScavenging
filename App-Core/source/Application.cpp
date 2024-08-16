#include "Application.h"
#include "AssetManger.h"

Application::Application(AppInfo& info)
{
    m_info = info;
    m_window.Open(m_info.WinSize.x, m_info.WinSize.y, m_info.title);
    InitAudioDevice();
}
Application::~Application()
{
    AssetManager::Clean();
    CloseAudioDevice();
    m_window.Close();
}

void Application::Run()
{
    while(m_isRunning)
    {
        HandleEvents();
        OnUpdate();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            OnRender();
            OnRenderUI();

        EndDrawing();

    }
}
void Application::Quit()
{m_isRunning = false;}
void Application::HandleEvents()
{m_isRunning = !WindowShouldClose();}

void Application::OnUpdate(){}
void Application::OnRender(){}
void Application::OnRenderUI(){}


