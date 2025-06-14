#include "Queen.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 8; //number of offsets the queen can have

Queen::Queen(COLOURS pieceColour) : Piece(pieceColour, QUEEN) {}

bool Queen::isValidOffset(int currentPosition, int candidateOffset) { 

	int offset = getOffset(currentPosition, candidateOffset); //recieves the offset for a single move

	if (offset != ERROR_CODE) {

		return true;

	}

	return false;

}

bool Queen::isFirstColumnException(int currentPosition, int candidateOffset) { //prevents the queen from moving to the left when in the first column

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == LEFT || candidateOffset == BOTTOM_LEFT)) {

		return true;

	}

	return false;

}

bool Queen::isEighthColumnException(int currentPosition, int candidateOffset) { //prevents the queen from moving to the right when in the eighth column

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == RIGHT || candidateOffset == BOTTOM_RIGHT)) {

		return true;

	}

	return false;

}

bool Queen::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, offset, candidateOffset / offset, board);

}

bool Queen::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, offset, candidateOffset / offset, board);

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

		if (candidateOffset % QUEEN_MOVES[i] == 0 && candidateOffset / QUEEN_MOVES[i] > 0) { //checks wether the wanted offset is performable by the queen

			bool isException = false;

			for (size_t j = 0; j < candidateOffset / QUEEN_MOVES[i]; j++) { //checks if any square on the path to the destination is an exception

				if (isFirstColumnException(currentPosition + QUEEN_MOVES[i] * j, QUEEN_MOVES[i]) || isEighthColumnException(currentPosition + QUEEN_MOVES[i] * j, QUEEN_MOVES[i])) {

					isException = true;
					break;

				}

			}

			if (!isException) {

				return QUEEN_MOVES[i];

			}

		}

	}

	return ERROR_CODE;

}