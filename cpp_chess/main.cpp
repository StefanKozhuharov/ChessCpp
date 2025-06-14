#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "constants.h"
#include "Game.h"
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

int main()
{
    
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _setmode(_fileno(stdout), _O_U16TEXT);
    Game game;
    game.startGame();

}