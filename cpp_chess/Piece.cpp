#include "constants.h"
#include "Piece.h"

Piece::Piece() : pieceColour(NONE), pieceType(EMPTY), visualizationCode(L" ") {}

Piece::Piece(COLOURS pieceColour, PIECES pieceType) : pieceColour(pieceColour), pieceType(pieceType) {

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

void Piece::setPieceColour(COLOURS pieceColour) {

	this->pieceColour = pieceColour;
	updateVisualizationCode();

}

void Piece::setPieceType(PIECES pieceType) {

	this->pieceType = pieceType;
	updateVisualizationCode();

}

bool Piece::isEmpty() const {

		return pieceColour == NONE || pieceType == EMPTY;

}