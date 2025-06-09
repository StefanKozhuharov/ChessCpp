#include "Pawn.h"
#include "constants.h"

const int TWO_TOP = 16; //moves two squares up
const int NUMBER_OF_MOVES = 4;

Pawn::Pawn(COLOURS pieceColour) : Piece(pieceColour, PAWN, false) {

	const int PAWN_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT, 
		TOP, 
		TOP_RIGHT, 
		TWO_TOP

	};

}