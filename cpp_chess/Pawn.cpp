#include "Pawn.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4;

Pawn::Pawn(COLOURS pieceColour) : Piece(pieceColour, PAWN) {}

bool Pawn::isValidOffset(int currentPosition, int candidateOffset) {

	const int PAWN_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		TWO_TOP

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if ((candidateOffset == PAWN_MOVES[i] && getPieceColour() == WHITE) || (candidateOffset * -1 == PAWN_MOVES[i] && getPieceColour() == BLACK)) {

			return true;

		}

	}

	return false;

}

bool Pawn::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (candidateOffset % TOP_LEFT == 0 && getCanEnPassantLeft()) {

		return true;

	}

	if (candidateOffset % TOP_RIGHT == 0 && getCanEnPassantRight()) {

		return true;

	}

	if (candidateOffset % TWO_TOP == 0) {

		if (!getHasMoved() && isPathClear(currentPosition, candidateOffset / 2, 2, board)) {

			return true;

		}

		return false;

	}

	if (candidateOffset % TOP == 0) {

		return true;

	}

	return false;

}

bool Pawn::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (candidateOffset % TOP_RIGHT == 0 || candidateOffset % TOP_LEFT == 0) {

		return true;

	}

	return false;

}