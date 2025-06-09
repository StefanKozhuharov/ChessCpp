#pragma once
#include "constants.h"
#include "Piece.h"

bool isFirstColumn(int currentPosition) {

	if (currentPosition % 8 == 0) {

		return true;

	}

	return false;

}

bool isSecondColumn(int currentPosition) {

	if (currentPosition % 8 == 1) {

		return true;

	}

	return false;

}

bool isSeventhColumn(int currentPosition) {

	if (currentPosition % 8 == 6) {

		return true;

	}

	return false;

}

bool isEighthColumn(int currentPosition) {

	if (currentPosition % 8 == 7) {

		return true;

	}

	return false;

}

int getKingPosition(COLOURS pieceColour, Piece* board[BOARD_SIZE*BOARD_SIZE]) {

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		if (board[i]->getPieceType() == KING && board[i]->getPieceColour() == pieceColour) {

			return i;

		}

	}

	return -1;

}

bool isCheck(Piece* board[BOARD_SIZE * BOARD_SIZE], int kingPosition) {

	Piece* king = board[kingPosition];

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		Piece* currentPiece = board[i];
		
		if (currentPiece->getPieceColour() != king->getPieceColour() && currentPiece->isLegalMove(i, kingPosition, board)) {

			return true;

		}

	}

	return false;

}