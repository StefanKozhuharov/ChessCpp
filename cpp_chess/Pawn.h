#pragma once
#include "Piece.h"

class Pawn : public Piece {

private:

	bool isFirstColumnException(int currentPosition, int candidateOffset);
	bool isEighthColumnException(int currentPosition, int candidateOffset);

public:

	Pawn(COLOURS pieceColour);
	bool canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool isValidOffset(int currentPosition, int candidateOffset) override;

};