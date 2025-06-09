#pragma once
#include "Piece.h"

class King : public Piece {

private:

	bool isFirstColumnException(int currentPosition, int candidateOffset);
	bool isEighthColumnException(int currentPosition, int candidateOffset);
	bool isValidCastle(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]);

public:

	King(COLOURS pieceColour);
	bool canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool isValidOffset(int currentPosition, int candidateOffset) override;

};