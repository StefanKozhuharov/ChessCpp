#include "Rook.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4;

Rook::Rook(COLOURS pieceColour) : Piece(pieceColour, ROOK, true) {}

bool Rook::isValidOffset(int currentPosition, int candidateOffset) {

	const int ROOK_MOVES[NUMBER_OF_MOVES] = {

		TOP,
		LEFT,
		RIGHT,
		BOTTOM

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset % ROOK_MOVES[i] == 0 && candidateOffset / ROOK_MOVES[i] > 0) {

			for (size_t j = 0; j < candidateOffset / ROOK_MOVES[i]; j++) {

				if (!isFirstColumnException(currentPosition + ROOK_MOVES[i] * j, ROOK_MOVES[i]) && !isEighthColumnException(currentPosition + ROOK_MOVES[i] * j, ROOK_MOVES[i])) {

					continue;

				}

				return false;

			}

			return true;

		}

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

	return true; //TODO adding check if they run into a piece on their path

}

bool Rook::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return true; //TODO adding check if they run into a piece on their path

}