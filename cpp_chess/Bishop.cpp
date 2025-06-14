#include "Bishop.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4; //number of different offsets the bishop can make

Bishop::Bishop(COLOURS pieceColour) : Piece(pieceColour, BISHOP) {}

bool Bishop::isValidOffset(int currentPosition, int candidateOffset) {

	int offset = getOffset(currentPosition, candidateOffset); //recives the offset of the bishop for a single move

	if (offset != ERROR_CODE) {

		return true;

	}

	return false;

}

bool Bishop::isFirstColumnException(int currentPosition, int candidateOffset) {

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == BOTTOM_LEFT)) { //prevents the bishop from moving left when he's in the first column

		return true;

	}

	return false;

}

bool Bishop::isEighthColumnException(int currentPosition, int candidateOffset) {

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == BOTTOM_RIGHT)) { //prevents the bishop from moving right when he's in the eighth column

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

		if (candidateOffset % BISHOP_MOVES[i] == 0 && candidateOffset / BISHOP_MOVES[i] > 0) { //checks wether the wanted offset is performable by the bishop

			bool isException = false;

			for (size_t j = 0; j < candidateOffset / BISHOP_MOVES[i]; j++) { //checks if any square on the path to the destination is an exception

				if (isFirstColumnException(currentPosition + BISHOP_MOVES[i] * j, BISHOP_MOVES[i]) || isEighthColumnException(currentPosition + BISHOP_MOVES[i] * j, BISHOP_MOVES[i])) {

					isException = true;
					break;

				}

			}

			if (!isException) {

				return BISHOP_MOVES[i];

			}

		}

	}

	return ERROR_CODE;

}