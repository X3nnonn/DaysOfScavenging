#pragma once

#include "Application.h"
#include "Player.h"
#include "Object.h"
#include "AssetManger.h"

enum AccessLevel
{
    ADMIN = 0,
    PLAYER,
    VIEWER,
};

class Game : public Application
{
public:
    Game(AppInfo& info);
    ~Game() = default;

    void OnUpdate() override;
    void OnRender() override;
    void OnRenderUI() override;

public:
private:
    void CheckAccess();
    void SetPlayer();

    void SetCamera();
    void AdjustCamera();
    void cameraRotation();
    void cameraZoom();

    void SetBoundry();
    void setWalls();
    void setSkyBox();
    void setGround();

private:
    Camera2D m_camera;

    Player m_player;

    Object m_ground;
    Object m_leftWall;

    AccessLevel ACCESS = ADMIN;
};
