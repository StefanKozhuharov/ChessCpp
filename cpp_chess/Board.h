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
	void copy(const Board& other);
	void free();

public:

	Board();
	~Board();
	Board& operator=(const Board& other);
	Board(const Board& other);
	Piece** getBoard();
	void printBoard(COLOURS playerColour);

};