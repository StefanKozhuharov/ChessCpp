#pragma once
#include "Board.h"
#include "Piece.h"

class Game {

private:

	Board board;
	char previousBoards[51][BOARD_SIZE * BOARD_SIZE + 1];
	int numberOfRepetitionsOfBoardState[51]{};
	int currentSavedBoardState = 0;
	int getCoordinates(char coordinate[2]);
	void executeMove(int currentPosition, int destination);
	void setEnPassant();
	void saveGame(COLOURS playerColour);
	void loadGame(COLOURS& playerColour);
	bool isDraw(COLOURS playerColour);
	bool isWin(COLOURS playerColour);
	bool hasLegalMoves(Piece* piece, int currentPosition);
	void saveBoardState();
	bool isKingSafe(COLOURS playerColour, int currentPosition, int destination);

public:

	void startGame();

};