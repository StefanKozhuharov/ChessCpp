#pragma once
#include "Board.h"
#include "Piece.h"

class Game {

private:

	Board board;
	int getCoordinates(char coordinate[2]);
	void executeMove(int currentPosition, int destination);
	void setEnPassant();
	void saveGame(COLOURS playerColour);
	void loadGame(COLOURS& playerColour);

public:

	void startGame();

};