#pragma once

#include "Application.h"
#include "Player.h"
#include "Object.h"


class Game : public Application
{
public:
    Game(AppInfo& info);
    ~Game() = default;

    void OnUpdate() override;
    void OnRender() override;
    void OnRenderUI() override;

    void SetPlayer();

    void SetCamera();
    void AdjustCamera();
    void cameraRotation();
    void cameraZoom();

    void SetBoundry();
    void setWalls();
    void setSkyBox();
    void setGround();

public:
    
private:
    Camera2D m_camera;

    Player m_player;

    
    Object m_ground;
    Object m_leftWall;

    std::string ACCESS[3] = {"ADMIN", "PLAYER", "VIEWER"};
    const char* MODE;
    
    void CheckAccess();

    

private:
    

};