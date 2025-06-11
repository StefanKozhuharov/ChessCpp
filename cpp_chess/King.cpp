#include "King.h"
#include "constants.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 10;
const int TWO_LEFT = -2;
const int TWO_RIGHT = 2;

King::King(COLOURS pieceColour) : Piece(pieceColour, KING) {}

bool King::isValidOffset(int currentPosition, int candidateOffset) {

	const int KING_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		TWO_LEFT,
		LEFT,
		TWO_RIGHT,
		RIGHT,
		BOTTOM_LEFT,
		BOTTOM,
		BOTTOM_RIGHT

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset == KING_MOVES[i]) {

			if (isFirstColumnException(currentPosition, candidateOffset) || isEighthColumnException(currentPosition, candidateOffset)) {

				return false;

			}

			return true;

		}

	}

	return false;

}

bool King::isFirstColumnException(int currentPosition, int candidateOffset) {

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == LEFT || candidateOffset == BOTTOM_LEFT || candidateOffset == TWO_LEFT)) {

		return true;

	}

	return false;

}

bool King::isEighthColumnException(int currentPosition, int candidateOffset) {

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == RIGHT || candidateOffset == BOTTOM_RIGHT || candidateOffset == TWO_RIGHT)) {

		return true;

	}

	return false;

}

bool King::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (candidateOffset == 2 || candidateOffset == -2) {

		return false;

	}

	return true;

}

bool King::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (candidateOffset == 2  || candidateOffset == -2) {

		return isValidCastle(currentPosition, destination, board);

	}

	return true;

}

bool King::isValidCastle(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	int rookPosition = (candidateOffset == 2 ? 1 : -2) + destination;
	int repetitions = candidateOffset == 2 ? 3 : 4;

	if (getHasMoved() || board[rookPosition]->getPieceType() != ROOK || board[rookPosition]->getHasMoved() || !isPathClear(currentPosition, candidateOffset / 2, repetitions, board) || isCheck(board, currentPosition)) {

		return false;

	}

	delete board[currentPosition + candidateOffset / 2];
	board[currentPosition + candidateOffset / 2] = board[currentPosition];
	board[currentPosition] = new Piece();

	if (isCheck(board, currentPosition + candidateOffset / 2)) {

		delete board[currentPosition];
		board[currentPosition] = board[currentPosition + candidateOffset / 2];
		board[currentPosition + candidateOffset / 2] = new Piece();

		return false;

	}

	delete board[currentPosition];
	board[currentPosition] = board[currentPosition + candidateOffset / 2];
	board[currentPosition + candidateOffset / 2] = new Piece();

	return true;

}