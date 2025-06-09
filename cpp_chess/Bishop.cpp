#include "Bishop.h"
#include "constants.h"

Bishop::Bishop(COLOURS pieceColour) : Piece(pieceColour, BISHOP) {

	const int BISHOP_MOVES[4] = {

		-9, //moves to the top left corner
		-7, //moves to the top right corner
		7, //moves to the bottom left corner
		9 //moves to the bottom right corner

	};

}