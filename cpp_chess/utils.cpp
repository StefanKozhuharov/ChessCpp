#include "constants.h"
#include "Piece.h"
#include "utils.h"
#include <iostream>

using namespace std;

bool isFirstColumn(int currentPosition) { //checks if the current position of the piece is in the first column

	if (currentPosition % 8 == 0) {

		return true;

	}

	return false;

}

bool isSecondColumn(int currentPosition) { //checks if the current position of the piece is in the second column

	if (currentPosition % 8 == 1) {

		return true;

	}

	return false;

}

bool isSeventhColumn(int currentPosition) { //checks if the current position of the piece is in the seventh column

	if (currentPosition % 8 == 6) {

		return true;

	}

	return false;

}

bool isEighthColumn(int currentPosition) { //checks if the current position of the piece is in the eighth column

	if (currentPosition % 8 == 7) {

		return true;

	}

	return false;

}

int getKingPosition(COLOURS pieceColour, Piece* board[BOARD_SIZE * BOARD_SIZE]) { //returns the position of the king by going through the board untill he is found

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		if (board[i]->getPieceType() == KING && board[i]->getPieceColour() == pieceColour) {

			return i;

		}

	}

	return -1;

}

bool isCheck(Piece* board[BOARD_SIZE * BOARD_SIZE], int kingPosition) { //checks if any enemy piece has an attacking move that can capture the king

	Piece* king = board[kingPosition];

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		Piece* currentPiece = board[i];

		if (currentPiece->getPieceColour() != king->getPieceColour() && currentPiece->isLegalMove(i, kingPosition, board)) {

			return true;

		}

	}

	return false;

}

bool isPathClear(int currentPosition, int candidateOffset, int repititions, Piece* board[BOARD_SIZE * BOARD_SIZE]) { //checks if every square on the path of a piece is empty

	int nextSquare = currentPosition;

	for (size_t i = 1; i < repititions; i++) {

		nextSquare += candidateOffset;

		if (!board[nextSquare]->isEmpty()) {

			return false;

		}

	}

	return true;

}