#include "King.h"
#include "constants.h"

King::King(COLOURS pieceColour) : Piece(pieceColour, KING) {

	const int kingMoves[8] = {

		-9, //moves to the top left corner
		-8, //moves one square up
		-7, //moves to the top right corner
		-1, //moves one square left
		1, //moves one square right
		7, //moves to the top left corner 
		8, //moves one square down
		9 //moves to the top right corner

	};

}