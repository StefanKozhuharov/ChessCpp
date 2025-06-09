#include "Knight.h"
#include "constants.h"

Knight::Knight(COLOURS pieceColour) : Piece(pieceColour, KNIGHT) {

	const int KNIHGT_MOVES[8] = {

		-17, //moves two squares up one left
		-15, //moves two squared up one right
		-10, //moves one square up two left
		-6, //moves one square up two right
		6, //moves one square down two left
		10, //moves one square down two right
		15, //two squares down one left
		17 //two squares down one right

	};

}