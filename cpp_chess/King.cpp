#include "King.h"
#include "utils.h"

const int NUMBER_OF_MOVES = 10; //number of different offsets the king can have

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

		if (candidateOffset == KING_MOVES[i]) { //checks if the wanted offset is possible for the king to do

			if (isFirstColumnException(currentPosition, candidateOffset) || isEighthColumnException(currentPosition, candidateOffset)) { //prevents exceptions

				return false;

			}

			return true;

		}

	}

	return false;

}

bool King::isFirstColumnException(int currentPosition, int candidateOffset) { //prevents moving to the left in the first column

	if (isFirstColumn(currentPosition) && (candidateOffset == TOP_LEFT || candidateOffset == LEFT || candidateOffset == BOTTOM_LEFT || candidateOffset == TWO_LEFT)) {

		return true;

	}

	return false;

}

bool King::isEighthColumnException(int currentPosition, int candidateOffset) { //prevents moving to the right in the eighth column

	if (isEighthColumn(currentPosition) && (candidateOffset == TOP_RIGHT || candidateOffset == RIGHT || candidateOffset == BOTTOM_RIGHT || candidateOffset == TWO_RIGHT)) {

		return true;

	}

	return false;

}

bool King::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) { //executes an attack

	int candidateOffset = destination - currentPosition;

	if (candidateOffset == TWO_RIGHT || candidateOffset == TWO_LEFT) { //prevents attacking with offsets of a castle 

		return false;

	}

	return true;

}

bool King::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (candidateOffset == TWO_RIGHT  || candidateOffset == TWO_LEFT) { //checks if the player is trying to castle and if it is valid

		return isValidCastle(currentPosition, destination, board);

	}

	return true;

}

bool King::isValidCastle(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	int rookPosition = (candidateOffset == 2 ? 1 : -2) + destination; //calculates the rook's position depending on if it's a short or long caslte
	int repetitions = candidateOffset == 2 ? 3 : 4; //sets the times the king has to move by one depending on if it's a short or long castle

	//prevents the castle if either the king has moved, the piece where the rook should be is not a rook, the rook has moved, the path to the castle destination is not clear or the king would be in check on it's way or at the destination

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