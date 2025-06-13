#include "Bishop.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4;

Bishop::Bishop(COLOURS pieceColour) : Piece(pieceColour, BISHOP) {}

bool Bishop::isValidOffset(int currentPosition, int candidateOffset) {

	int offset = getOffset(currentPosition, candidateOffset);

	if (offset != ERROR_CODE) {

		for (size_t j = 0; j < candidateOffset / offset; j++) {

			if (isFirstColumnException(currentPosition + offset * j, offset) || isEighthColumnException(currentPosition + offset * j, offset)) {

				return false;

			}

		}

		return true;

	}

	return false;

}

bool Bishop::isFirstColumnException(int currentPosition, int candidateOffset) {

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == BOTTOM_LEFT)) {

		return true;

	}

	return false;

}

bool Bishop::isEighthColumnException(int currentPosition, int candidateOffset) {

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == BOTTOM_RIGHT)) {

		return true;

	}

	return false;

}

bool Bishop::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, offset, candidateOffset / offset, board);


}

bool Bishop::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, offset, candidateOffset / offset, board);

}

int Bishop::getOffset(int currentPosition, int candidateOffset) {

	const int BISHOP_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_RIGHT

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset % BISHOP_MOVES[i] == 0 && candidateOffset / BISHOP_MOVES[i] > 0) {

			return BISHOP_MOVES[i];

		}

	}

	return ERROR_CODE;

}