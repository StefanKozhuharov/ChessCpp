#include "Queen.h"
#include "constants.h"

const int NUMBER_OF_MOVES = 8;

Queen::Queen(COLOURS pieceColour) : Piece(pieceColour, QUEEN, false) {

	const int QUEEN_MOVES[NUMBER_OF_MOVES] = {

		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		LEFT,
		RIGHT,
		BOTTOM_LEFT,
		BOTTOM,
		BOTTOM_RIGHT

	};

}