#pragma once
#include "Board.h"
#include "Piece.h"

class Game {

private:

	Board board;
	int getCoordinates(char coordinate[2]);
	void executeMove();

public:

	void startGame();

};