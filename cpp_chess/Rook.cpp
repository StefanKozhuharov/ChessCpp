#include "Rook.h"
#include "constants.h"

const int NUMBER_OF_MOVES = 4;

Rook::Rook(COLOURS pieceColour) : Piece(pieceColour, ROOK, true) {

	const int ROOK_MOVES[NUMBER_OF_MOVES] = {

		TOP, 
		LEFT, 
		RIGHT, 
		BOTTOM 

	};

}