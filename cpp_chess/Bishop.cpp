#include "Bishop.h"
#include "constants.h"

const int NUMBER_OF_MOVES = 4;

Bishop::Bishop(COLOURS pieceColour) : Piece(pieceColour, BISHOP, false) {

	const int BISHOP_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT, 
		TOP_RIGHT, 
		BOTTOM_LEFT,
		BOTTOM_RIGHT 

	};

}