#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "constants.h"
#include "Game.h"

using namespace std;

int main()
{
    
    _setmode(_fileno(stdout), _O_U16TEXT);
    Game game;
    game.startGame();

}