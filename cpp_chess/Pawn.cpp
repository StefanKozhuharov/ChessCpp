#include "Pawn.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4; //number of offsets the pawn can have

Pawn::Pawn(COLOURS pieceColour) : Piece(pieceColour, PAWN) {}

bool Pawn::isValidOffset(int currentPosition, int candidateOffset) {

	const int PAWN_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		TWO_TOP

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		//checks if the offset is correct for the specific colour of the pawn and if it is an exception

		if ((candidateOffset == PAWN_MOVES[i] && getPieceColour() == WHITE || (candidateOffset * -1 == PAWN_MOVES[i] && getPieceColour() == BLACK)) && !isFirstColumnException(currentPosition, candidateOffset) && !isEighthColumnException(currentPosition, candidateOffset)) {

			return true;

		}

	}

	return false;

}

bool Pawn::isFirstColumnException(int currentPosition, int candidateOffset) { //prevents the pawn from going left in the first column

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == BOTTOM_LEFT)) {

		return true;

	}

	return false;

}

bool Pawn::isEighthColumnException(int currentPosition, int candidateOffset) { //prevents the pawn from going right in the eighth column

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == BOTTOM_RIGHT)) {

		return true;

	}

	return false;

}

bool Pawn::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (candidateOffset % TOP_LEFT == 0 && getCanEnPassantLeft()) { //checks if the move is an en passant to the left

		return true;

	}

	if (candidateOffset % TOP_RIGHT == 0 && getCanEnPassantRight()) { //checks if the move is an en passant to the right

		return true;

	}

	if (candidateOffset % TWO_TOP == 0) { //checks if the pawn has moved before and is it's path clear to determine wether it can move up twice or not

		if (!getHasMoved() && isPathClear(currentPosition, candidateOffset / 2, 2, board)) {

			return true;

		}

		return false;

	}

	if (candidateOffset % TOP == 0) { //moves up once

		return true;

	}

	return false;

}

bool Pawn::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) { 

	int candidateOffset = destination - currentPosition;

	if (candidateOffset % TOP_RIGHT == 0 || candidateOffset % TOP_LEFT == 0) { //checks if the move is either to the left or right diagonal

		return true;

	}

	return false;

}