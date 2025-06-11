#pragma once
#include "Piece.h"

class Queen : public Piece {

private:

	bool isFirstColumnException(int currentPosition, int candidateOffset);
	bool isEighthColumnException(int currentPosition, int candidateOffset);
	int getOffset(int currentPosition, int candidateOffset);

public:

	Queen(COLOURS pieceColour);
	bool canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool isValidOffset(int currentPosition, int candidateOffset) override;

};