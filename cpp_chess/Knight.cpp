#include "Knight.h"
#include "utils.h"

const int KNIGHT_UP_LEFT = -17; // moves two squares up, one left
const int KNIGHT_UP_RIGHT = -15; // moves two squares up, one right
const int KNIGHT_LEFT_UP = -10; // moves one square up, two left
const int KNIGHT_RIGHT_UP = -6;  // moves one square up, two right
const int KNIGHT_LEFT_DOWN = 6;   // moves one square down, two left
const int KNIGHT_RIGHT_DOWN = 10;  // moves one square down, two right
const int KNIGHT_DOWN_LEFT = 15;  // moves two squares down, one left
const int KNIGHT_DOWN_RIGHT = 17;  // moves two squares down, one right
const int NUMBER_OF_MOVES = 8; //number of different offsets the knight can have

Knight::Knight(COLOURS pieceColour) : Piece(pieceColour, KNIGHT) {}

bool Knight::isValidOffset(int currentPosition, int candidateOffset) { //checks if the wanted offset is valid

	const int KNIGHT_MOVES[NUMBER_OF_MOVES] = {

		KNIGHT_UP_LEFT,
		KNIGHT_UP_RIGHT,
		KNIGHT_LEFT_UP,
		KNIGHT_RIGHT_UP,
		KNIGHT_LEFT_DOWN,
		KNIGHT_RIGHT_DOWN,
		KNIGHT_DOWN_LEFT,
		KNIGHT_DOWN_RIGHT

	};

	for (size_t i = 0; i < NUMBER_OF_MOVES; i++) {

		if (candidateOffset == KNIGHT_MOVES[i]) {

			if (isFirstColumnException(currentPosition, candidateOffset) || isEighthColumnException(currentPosition, candidateOffset) || isSecondColumnException(currentPosition, candidateOffset) || isSeventhColumnException(currentPosition, candidateOffset)) {

				return false;

			}

			return true;

		}

	}

	return false;

}

bool Knight::isFirstColumnException(int currentPosition, int candidateOffset) { //prevents the knight from moving left in the first column

	if (isFirstColumn(currentPosition) && (candidateOffset == KNIGHT_UP_LEFT || candidateOffset == KNIGHT_LEFT_UP || candidateOffset == KNIGHT_LEFT_DOWN || candidateOffset == KNIGHT_DOWN_LEFT)) {

		return true;

	}

	return false;

}

bool Knight::isSecondColumnException(int currentPosition, int candidateOffset) { //prevents the knight from moving left twice in the second column

	if (isSecondColumn(currentPosition) && (candidateOffset == KNIGHT_LEFT_UP || candidateOffset == KNIGHT_LEFT_DOWN)) {

		return true;

	}

	return false;

}

bool Knight::isSeventhColumnException(int currentPosition, int candidateOffset) { //prevents the knight from moving right twice in the seventh column

	if (isSeventhColumn(currentPosition) && (candidateOffset == KNIGHT_RIGHT_UP || candidateOffset == KNIGHT_RIGHT_DOWN)) {

		return true;

	}

	return false;

}

bool Knight::isEighthColumnException(int currentPosition, int candidateOffset) { //prevents the knight from moving right in the eighth column

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