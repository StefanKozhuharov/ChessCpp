#include "constants.h"
#include "Piece.h"

Piece::Piece() : pieceColour(NONE), pieceType(EMPTY), visualizationCode(L" "), hasMoved(false), canEnPassantLeft(false), canEnPassantRight(false){}

Piece::Piece(COLOURS pieceColour, PIECES pieceType) : pieceColour(pieceColour), pieceType(pieceType), hasMoved(false), canEnPassantLeft(false), canEnPassantRight(false) {

	updateVisualizationCode();

}

COLOURS Piece::getPieceColour() const {

	return pieceColour;

}

PIECES Piece::getPieceType() const {

	return pieceType;

}

const wchar_t* Piece::getVisualizationCode() const {

	return visualizationCode;

}

bool Piece::getHasMoved() const {

	return hasMoved;

}

bool Piece::getCanEnPassantLeft() const {

	return canEnPassantLeft;

}

bool Piece::getCanEnPassantRight() const {

	return canEnPassantRight;

}

void Piece::updateVisualizationCode() {

	if (pieceColour == WHITE) {

		visualizationCode = WHITE_PIECES[pieceType];

	}
	else if (pieceColour == BLACK) {

		visualizationCode = BLACK_PIECES[pieceType];

	}
	else {

		visualizationCode = L" ";

	}

}

bool Piece::canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return false;

}

bool Piece::canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	return false;

}

void Piece::setPieceColour(COLOURS pieceColour) {

	this->pieceColour = pieceColour;
	updateVisualizationCode();

}

void Piece::setPieceType(PIECES pieceType) {

	this->pieceType = pieceType;
	updateVisualizationCode();

}

void Piece::setHasMoved(bool hasMoved) {

	this->hasMoved = hasMoved;

}

void Piece::setCanEnPassantLeft(bool canEnPassantLeft) {

	this->canEnPassantLeft = canEnPassantLeft;

}

void Piece::setCanEnPassantRight(bool canEnPassantRight) {

	this->canEnPassantRight = canEnPassantRight;

}

bool Piece::isEmpty() const {

		return pieceColour == NONE || pieceType == EMPTY;

}

bool Piece::isValidOffset(int currentPosition, int candidateOffset) {

	return false;

}

bool Piece::isLegalMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) {

	int candidateOffset = destination - currentPosition;

	if (destination < 0 || destination >= BOARD_SIZE * BOARD_SIZE || !isValidOffset(currentPosition, candidateOffset) || isEmpty()) {

		return false;

	}

	if (board[destination]->getPieceColour() == NONE) {

		return canMove(currentPosition, destination, board);

	}
	else if (board[destination]->getPieceColour() != board[currentPosition]->getPieceColour()) {

		return canAttack(currentPosition, destination, board);

	}

		return false;

}