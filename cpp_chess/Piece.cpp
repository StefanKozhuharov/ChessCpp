#include "constants.h"
#include "Piece.h"
#include <iostream>

using namespace std;

const wchar_t* PIECE_CODES[] = {

	L"\u265A", //king - 0 same as the type
	L"\u265B", //queen - 1 same as the type
	L"\u265C", //rook - 2 same as the type
	L"\u265D", //bishop - 3 same as the type
	L"\u265E", //knight - 4 same as the type
	L"\u265F" //pawn - 5 same as the type

};

//stores the colour of a piece , it's type, it's visualization code, wether it has moved, wether it can en passant to the right and to the left

Piece::Piece() : pieceColour(NONE), pieceType(EMPTY), visualizationCode(L" "), hasMoved(false), canEnPassantLeft(false), canEnPassantRight(false) {}

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

	if (pieceColour == NONE) {

		visualizationCode = L" ";

	}
	else {

		visualizationCode = PIECE_CODES[pieceType];

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

bool Piece::isEmpty() const { //checks if the selected square is empty

	return pieceColour == NONE || pieceType == EMPTY;

}

bool Piece::isValidOffset(int currentPosition, int candidateOffset) { 

	return false;

}

bool Piece::isLegalMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]) { //checks if the wanted move is legal

	int candidateOffset = destination - currentPosition;

	//checks if the destination is outside the confines of the board, wether it's offset is valid and wether we have even selected a piece

	if (destination < 0 || destination >= BOARD_SIZE * BOARD_SIZE || !isValidOffset(currentPosition, candidateOffset) || isEmpty()) {

		return false;

	}

	if (board[destination]->getPieceColour() == NONE) { //executes the canMove function if the destination square is empty

		return canMove(currentPosition, destination, board);

	}
	else if (board[destination]->getPieceColour() != board[currentPosition]->getPieceColour()) { //executes the canAttack function if the destination square is an enemy piece

		return canAttack(currentPosition, destination, board);

	}

	return false;

}