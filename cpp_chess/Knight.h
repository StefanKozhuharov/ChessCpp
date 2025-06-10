#pragma once
#include "Piece.h"

class Knight : public Piece {

private:

	bool isFirstColumnException(int currentPosition, int candidateOffset);
	bool isSecondColumnException(int currentPosition, int candidateOffset);
	bool isSeventhColumnException(int currentPosition, int candidateOffset);
	bool isEighthColumnException(int currentPosition, int candidateOffset);

public:

	Knight(COLOURS pieceColour);
	bool canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) override;
	bool isValidOffset(int currentPosition, int candidateOffset) override;

};