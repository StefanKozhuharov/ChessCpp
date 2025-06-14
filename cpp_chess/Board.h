#pragma once
#include "Piece.h"
#include "constants.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

class Board {

private:

	Piece* board[BOARD_SIZE * BOARD_SIZE];

	void setupPawns(COLOURS pieceColour, int row);
	void setupBackRank(COLOURS pieceColour, int row);
	void setupEmptySquares();
	void setColour(int textColour, int bgColour);
	void resetColour();

public:

	Board();
	Piece** getBoard();
	void printBoard(COLOURS playerColour);

};