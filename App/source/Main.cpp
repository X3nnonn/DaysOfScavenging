#include "Base.h"
#include "Game.h"

int main()
{
    AppInfo info;
    info.WinSize.x = DefWinWidth;
    info.WinSize.y = DefWinHeight;
    info.title = "Window Created Successfully!";

    Game game(info);

    game.Run();

    return 0;
}
