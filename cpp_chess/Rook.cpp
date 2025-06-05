#include "Rook.h"
#include "constants.h"

Rook::Rook(COLOURS pieceColour) : Piece(pieceColour, ROOK) {

	const int rookMoves[4] = {

		-8, //moves one square up
		-1, //moves one square left
		1, //moves one square right
		8 //moves one square down

	};

}