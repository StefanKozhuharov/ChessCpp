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

	void setupPawns(COLOURS pieceColour, int row); //first row is 0 second is 1 etc.
	void setupBackRank(COLOURS pieceColour, int row);

public:

	Piece** getBoard();
	void printBoard();

};