#include "Bishop.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4;

Bishop::Bishop(COLOURS pieceColour) : Piece(pieceColour, BISHOP, false) {}

bool Bishop::isValidOffset(int currentPosition, int candidateOffset) {

	const int BISHOP_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_RIGHT

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset % BISHOP_MOVES[i] == 0 && candidateOffset / BISHOP_MOVES[i] > 0) {

			for (size_t j = 0; j < candidateOffset / BISHOP_MOVES[i]; j++) {

				if (!isFirstColumnException(currentPosition + BISHOP_MOVES[i] * j, BISHOP_MOVES[i]) && !isEighthColumnException(currentPosition + BISHOP_MOVES[i] * j, BISHOP_MOVES[i])) {

					continue;

				}

				return false;

			}

			return true;

		}

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

	return true; //TODO adding check if they run into a piece on their path

}

bool Bishop::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return true; //TODO adding check if they run into a piece on their path

}