#include "Queen.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 8;

Queen::Queen(COLOURS pieceColour) : Piece(pieceColour, QUEEN, false) {}

bool Queen::isValidOffset(int currentPosition, int candidateOffset) {

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

bool Queen::isFirstColumnException(int currentPosition, int candidateOffset) {

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == LEFT || candidateOffset == BOTTOM_LEFT)) {

		return true;

	}

	return false;

}

bool Queen::isEighthColumnException(int currentPosition, int candidateOffset) {

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == RIGHT || candidateOffset == BOTTOM_RIGHT)) {

		return true;

	}

	return false;

}

bool Queen::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, candidateOffset, candidateOffset / offset, board);

}

bool Queen::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, candidateOffset, candidateOffset / offset, board);

}

int Queen::getOffset(int currentPosition, int candidateOffset) {

	const int QUEEN_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		LEFT,
		RIGHT,
		BOTTOM_LEFT,
		BOTTOM,
		BOTTOM_RIGHT

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset % QUEEN_MOVES[i] == 0 && candidateOffset / QUEEN_MOVES[i] > 0) {

			return QUEEN_MOVES[i];

		}

	}

	return ERROR_CODE;

}