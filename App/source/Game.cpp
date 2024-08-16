#include "Game.h"

//_____________
/*
    Constructor Settings
*/

Game::Game(AppInfo& info) : Application(info)
{
    SetPlayer();
    SetCamera();
    //SetBoundry();
}

//-------------
/*
    Camera Settings
*/

void Game::SetPlayer()
{
    m_player.bodyDim.width = 50;
    m_player.bodyDim.height = 50;
    m_player.color = RED;
}

//-------------
/*
    Camera Settings
*/

void Game::SetCamera()
{
    m_camera.target = { m_player.pos.x + float(m_player.bodyDim.width/2), m_player.pos.y + float(m_player.bodyDim.height/2) };
    m_camera.offset = { DefWinWidth/2, DefWinHeight/2 };
    m_camera.rotation = 0.0f;
    m_camera.zoom = .75f;
}

void Game::AdjustCamera()
{
    cameraRotation();
    cameraZoom();

    if (IsKeyPressed(KEY_R))
    {
        m_camera.zoom = 1.0f;
        m_camera.rotation = 0.0f;
    }

}
void Game::cameraRotation()
{
    if (IsKeyDown(KEY_P)) m_camera.rotation--;
    else if (IsKeyDown(KEY_O)) m_camera.rotation++;

    /* Limit camera rotation to 80 degrees (-40 to 40) */

    if (m_camera.rotation > 40) m_camera.rotation = 40;
    else if (m_camera.rotation < -40) m_camera.rotation = -40;

    //printf("< %f >\n", camera.rotation);    
}
void Game::cameraZoom()
{
    m_camera.zoom += ((float)GetMouseWheelMove()*0.05f);

    if (m_camera.zoom > 3.0f) m_camera.zoom = 3.0f;
    else if (m_camera.zoom < 0.1f) m_camera.zoom = 0.1f;

    //printf("< %f >\n", camera.zoom);
}

//-------------
/*
    Level Boundry Settings
*/

void Game::SetBoundry()
{
    setGround();
    setWalls();
    setSkyBox();
}

void Game::setGround()
{
    

    m_ground.object.x = (DefWinWidth/2-m_player.bodyDim.width*3)-(m_ground.width/2);
    m_ground.object.y = DefWinHeight*.8;
    m_ground.object.width = 1000;
    m_ground.object.height = 400;
    m_ground.color = DARKGRAY;

    m_ground.Draw();


    if (m_player.body.right <= m_ground.objectBody.left && m_player.body.bottom <= m_ground.objectBody.top)
    {
        m_player.ground += m_player.body.bottom + m_player.bodyDim.width*2;

    }else if(m_player.body.left >= m_ground.objectBody.right && m_player.body.bottom <= m_ground.objectBody.top)
    {
        m_player.ground += m_player.body.bottom + m_player.bodyDim.width*2;

    }else{
        m_player.ground = m_ground.object.y;
    }

}
void Game::setWalls()
{
    m_leftWall.object.x = 0;
    m_leftWall.object.y = 0;
    m_leftWall.object.width = 100;
    m_leftWall.object.height = DefWinHeight-m_player.ground;
    m_leftWall.color = DARKGRAY;
}
void Game::setSkyBox()
{}

//-------------
/*
    ADMIN Settings
*/

void Game::CheckAccess()
{
    if ( IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_BACKSLASH) ) MODE = ACCESS[0].c_str(); printf("%s", MODE);
    if ( IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_BACKSLASH) ) MODE = ACCESS[1].c_str(); printf("%s", MODE);
    if ( IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_BACKSLASH) ) MODE = ACCESS[2].c_str(); printf("%s", MODE);
    
    
}

//-------------
/*
    Main Game Settings
*/

void Game::OnUpdate()
{
    //CheckAccess();

    m_camera.target = { m_player.pos.x + float(m_player.bodyDim.width/2), m_player.pos.y + float(m_player.bodyDim.height/2) }; //printf(V2_FMT, V2_OPEN(m_camera.target));
    
    if ( IsKeyDown(KEY_LEFT_CONTROL) ) { AdjustCamera(); }
    
    m_player.Update();

}
void Game::OnRender()
{
    BeginMode2D(m_camera);
        //SetBoundry();
        m_player.Draw();
        
    EndMode2D();
}
void Game::OnRenderUI()
{
    
}

//-------------
