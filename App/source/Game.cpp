#include "Game.h"
#include "Base.h"

static Texture* player;
static float frameWidth;
static float frameHeight;

//_____________
/*
    Constructor Settings
*/

Game::Game(AppInfo& info) : Application(info)
{

    

    SetPlayer();
    // SetCamera();
    // SetBoundry();
}

//-------------
/*
    Camera Settings
*/

void Game::SetPlayer()
{
    AssetManager::LoadTexture("player", "assets/textures/playerIdle.png");
    player = AssetManager::GetTexture("player");
    frameWidth = player->width / 11.f;
    frameHeight = player->height;
}

//-------------
/*
    Camera Settings
*/

void Game::SetCamera()
{
    m_camera.target = {m_player.body.pos.x + float(m_player.body.scale.width / 2),
                       m_player.body.pos.y + float(m_player.body.scale.height / 2)};
    m_camera.offset = {DEFAULT_WINDOW_WIDTH / 2.f, DEFAULT_WINDOW_HEIGHT / 2.f};
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
    if (IsKeyDown(KEY_P))
        m_camera.rotation--;
    else if (IsKeyDown(KEY_O))
        m_camera.rotation++;

    /* Limit camera rotation to 80 degrees (-40 to 40) */

    if (m_camera.rotation > 40.f)
        m_camera.rotation = 40.f;
    else if (m_camera.rotation < -40.f)
        m_camera.rotation = -40.f;

    // printf("< %f >\n", camera.rotation);
}
void Game::cameraZoom()
{
    m_camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

    if (m_camera.zoom > 3.0f)
        m_camera.zoom = 3.0f;
    else if (m_camera.zoom < 0.1f)
        m_camera.zoom = 0.1f;

    // printf("< %f >\n", camera.zoom);
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


}
void Game::setWalls()
{

}
void Game::setSkyBox() {}

//-------------
/*
    ADMIN Settings
*/

void Game::CheckAccess()
{
    /*
        if ( IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyDown(KEY_LEFT_ALT) &&
       IsKeyPressed(KEY_BACKSLASH) ) {ACCESS = (AccessLevel)0;} if ( IsKeyDown(KEY_LEFT_CONTROL) &&
       IsKeyPressed(KEY_BACKSLASH) ) {ACCESS = PLAYER;} if ( IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_LEFT_SHIFT) &&
       IsKeyPressed(KEY_BACKSLASH) ) {ACCESS = VIEWER; }
    */

    u32 key = GetKeyPressed();
    switch (key)
    {
        case KEY_F1:
        {
            ACCESS = ADMIN;
            break;
        }

        case KEY_F2:
        {
            ACCESS = PLAYER;
            break;
        }

        case KEY_F3:
        {
            ACCESS = VIEWER;
            break;
        }
    }
}

//-------------
/*
    Main Game Settings
*/

void Game::OnUpdate()
{
    CheckAccess();

    m_camera.target = {m_player.body.pos.x + float(m_player.body.scale.width / 2),
                       m_player.body.pos.y +
                           float(m_player.body.scale.height / 2)}; // printf(V2_FMT, V2_OPEN(m_camera.target));

    if (ACCESS == ADMIN && IsKeyDown(KEY_LEFT_CONTROL))
    {
        AdjustCamera();
    }

    m_player.Update();
}
void Game::OnRender()
{
    BeginMode2D(m_camera);
    // SetBoundry();
    //
    EndMode2D();

    m_player.Draw();

    Rectangle srcRec = {0, 0, frameWidth, frameHeight};
    Rectangle destRec = {m_player.body.pos.x, m_player.body.pos.y, frameWidth * 2.0f, frameHeight * 2.0f};

    DrawTexturePro(*player, srcRec, destRec, {0, 0}, 0, WHITE);
}
void Game::OnRenderUI() {}

//-------------