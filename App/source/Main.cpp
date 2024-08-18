#include "Base.h"
#include "Game.h"

int main()
{
    AppInfo info;
    info.WinSize.x = DEFAULT_WINDOW_WIDTH;
    info.WinSize.y = DEFAULT_WINDOW_HEIGHT;
    info.title = "Days of Scavenging";

    Game game(info);
    game.Run();

    return 0;
}
