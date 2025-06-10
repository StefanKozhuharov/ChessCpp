#include "Knight.h"
#include "constants.h"
#include "utils.h"

const int KNIGHT_UP_LEFT = -17; // moves two squares up, one left
const int KNIGHT_UP_RIGHT = -15; // moves two squares up, one right
const int KNIGHT_LEFT_UP = -10; // moves one square up, two left
const int KNIGHT_RIGHT_UP = -6;  // moves one square up, two right
const int KNIGHT_LEFT_DOWN = 6;   // moves one square down, two left
const int KNIGHT_RIGHT_DOWN = 10;  // moves one square down, two right
const int KNIGHT_DOWN_LEFT = 15;  // moves two squares down, one left
const int KNIGHT_DOWN_RIGHT = 17;  // moves two squares down, one right
const int NUMBER_OF_MOVES = 8;

Knight::Knight(COLOURS pieceColour) : Piece(pieceColour, KNIGHT, false) {}

bool Knight::isValidOffset(int currentPosition, int candidateOffset) {

	const int KNIGHT_MOVES[NUMBER_OF_MOVES] = {

		KNIGHT_UP_LEFT,
		KNIGHT_UP_RIGHT,
		KNIGHT_LEFT_UP,
		KNIGHT_RIGHT_UP,
		KNIGHT_LEFT_DOWN,
		KNIGHT_DOWN_RIGHT,
		KNIGHT_DOWN_LEFT,
		KNIGHT_DOWN_RIGHT

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset == KNIGHT_MOVES[i]) {

			if (!isFirstColumnException(currentPosition, candidateOffset) && !isEighthColumnException(currentPosition, candidateOffset) && !isSecondColumnException(currentPosition, candidateOffset) && !isSeventhColumnException(currentPosition, candidateOffset)) {

				return true;

			}

			return false;

		}

	}

	return false;

}

bool Knight::isFirstColumnException(int currentPosition, int candidateOffset) {

	if (isFirstColumn(currentPosition) && (candidateOffset == KNIGHT_UP_LEFT || candidateOffset == KNIGHT_LEFT_UP || candidateOffset == KNIGHT_LEFT_DOWN || candidateOffset == KNIGHT_DOWN_LEFT)) {

		return true;

	}

	return false;

}

bool Knight::isSecondColumnException(int currentPosition, int candidateOffset) {

	if (isSecondColumn(currentPosition) && (candidateOffset == KNIGHT_LEFT_UP || candidateOffset == KNIGHT_LEFT_DOWN)) {

		return true;

	}

	return false;

}

bool Knight::isSeventhColumnException(int currentPosition, int candidateOffset) {

	if (isSeventhColumn(currentPosition) && (candidateOffset == KNIGHT_RIGHT_UP || candidateOffset == KNIGHT_RIGHT_DOWN)) {

		return true;

	}

	return false;

}

bool Knight::isEighthColumnException(int currentPosition, int candidateOffset) {

	if (isEighthColumn(currentPosition) && (candidateOffset == KNIGHT_UP_RIGHT || candidateOffset == KNIGHT_RIGHT_UP || candidateOffset == KNIGHT_RIGHT_DOWN || candidateOffset == KNIGHT_DOWN_RIGHT)) {

		return true;

	}

	return false;

}

bool Knight::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return true;

}

bool Knight::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return true;

}