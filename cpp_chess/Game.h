#pragma once
#include "Board.h"
#include "Piece.h"

class Game {

private:

	Board board;
	int getCoordinates(char coordinate[2]);
	void executeMove(int currentPosition, int destination);

public:

	void startGame();

};