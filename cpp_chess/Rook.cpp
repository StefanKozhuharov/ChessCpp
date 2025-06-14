#include "Rook.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 4; //number of offsets the rook can have

Rook::Rook(COLOURS pieceColour) : Piece(pieceColour, ROOK) {}

bool Rook::isValidOffset(int currentPosition, int candidateOffset) {

	int offset = getOffset(currentPosition, candidateOffset); //recieves the offset for a single move

	if (offset != ERROR_CODE) {

		return true;

	}

	return false;

}

bool Rook::isFirstColumnException(int currentPosition, int candidateOffset) { //prevents the rook from moving left when in the first column

	if (isFirstColumn(currentPosition) && candidateOffset == LEFT) {

		return true;

	}

	return false;

}

bool Rook::isEighthColumnException(int currentPosition, int candidateOffset) { //prevents the rook from moving right when in the eighth column

	if (isEighthColumn(currentPosition) && candidateOffset == RIGHT) {

		return true;

	}

	return false;

}

bool Rook::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, offset, candidateOffset / offset, board);

}

bool Rook::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;
	int offset = getOffset(currentPosition, candidateOffset);

	return isPathClear(currentPosition, offset, candidateOffset / offset, board);

}

int Rook::getOffset(int currentPosition, int candidateOffset) {

	const int ROOK_MOVES[NUMBER_OF_MOVES] = {

		TOP,
		LEFT,
		RIGHT,
		BOTTOM

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) { //checks wether the wanted offset is performable by the rook

		if (candidateOffset % ROOK_MOVES[i] == 0 && candidateOffset / ROOK_MOVES[i] > 0) { //checks wether the wanted offset is performable by the queen

			bool isException = false;

			for (size_t j = 0; j < candidateOffset / ROOK_MOVES[i]; j++) { //checks if any square on the path to the destination is an exception

				if (isFirstColumnException(currentPosition + ROOK_MOVES[i] * j, ROOK_MOVES[i]) || isEighthColumnException(currentPosition + ROOK_MOVES[i] * j, ROOK_MOVES[i])) {

					isException = true;
					break;

				}

			}

			if (!isException) {

				return ROOK_MOVES[i];

			}

		}

	}

	return ERROR_CODE;

}