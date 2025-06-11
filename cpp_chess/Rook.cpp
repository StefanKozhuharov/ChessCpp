#include "Rook.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4;

Rook::Rook(COLOURS pieceColour) : Piece(pieceColour, ROOK) {}

bool Rook::isValidOffset(int currentPosition, int candidateOffset) {

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

bool Rook::isFirstColumnException(int currentPosition, int candidateOffset) {

	if (isFirstColumn(currentPosition) && candidateOffset == LEFT) {

		return true;

	}

	return false;

}

bool Rook::isEighthColumnException(int currentPosition, int candidateOffset) {

	if (isEighthColumn(currentPosition) && candidateOffset == RIGHT) {

		return true;

	}

	return false;

}

bool Rook::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, candidateOffset, candidateOffset / offset, board);

}

bool Rook::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, candidateOffset, candidateOffset / offset, board);

}

int Rook::getOffset(int currentPosition, int candidateOffset) {

	const int ROOK_MOVES[NUMBER_OF_MOVES] = {

		TOP,
		LEFT,
		RIGHT,
		BOTTOM

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset % ROOK_MOVES[i] == 0 && candidateOffset / ROOK_MOVES[i] > 0) {

			return ROOK_MOVES[i];

		}

	}

	return ERROR_CODE;

}