#include "Pawn.h"
#include "constants.h"

Pawn::Pawn(COLOURS pieceColour) : Piece(pieceColour, PAWN) {

	const int PAWN_MOVES[4] = {

		7, //moves to the top left corner
		8, //moves one square up
		9, //moves to the top right corner
		16 //moves two squares up

	};

}