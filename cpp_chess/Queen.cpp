#include "Queen.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 8;

Queen::Queen(COLOURS pieceColour) : Piece(pieceColour, QUEEN, false) {}

bool Queen::isValidOffset(int currentPosition, int candidateOffset) {

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

			for (size_t j = 0; j < candidateOffset / QUEEN_MOVES[i]; j++) {

				if (!isFirstColumnException(currentPosition + QUEEN_MOVES[i] * j, QUEEN_MOVES[i]) && !isEighthColumnException(currentPosition + QUEEN_MOVES[i] * j, QUEEN_MOVES[i])) {

					continue;

				}

				return false;

			}

			return true;

		}

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

	return true; //TODO adding check if they run into a piece on their path

}

bool Queen::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return true; //TODO adding check if they run into a piece on their path

}