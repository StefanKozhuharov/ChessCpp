#include "Queen.h"
#include "constants.h"

Queen::Queen(COLOURS pieceColour) : Piece(pieceColour, QUEEN) {

	const int QUEEN_MOVES[8] = {

		-9, //moves to the top left corner
		-8, //moves one square up
		-7, //moves to the top right corner
		-1, //moves one square left
		1, //moves one square right
		7, //moves to the bottom left corner
		8, //moves one square down
		9 //moves to the bottom right corner

	};

}