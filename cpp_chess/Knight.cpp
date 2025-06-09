#include "Knight.h"
#include "constants.h"

const int KNIGHT_UP_LEFT = -17; // moves two squares up, one left
const int KNIGHT_UP_RIGHT = -15; // moves two squares up, one right
const int KNIGHT_LEFT_UP = -10; // moves one square up, two left
const int KNIGHT_RIGHT_UP = -6;  // moves one square up, two right
const int KNIGHT_LEFT_DOWN = 6;   // moves one square down, two left
const int KNIGHT_RIGHT_DOWN = 10;  // moves one square down, two right
const int KNIGHT_DOWN_LEFT = 15;  // moves two squares down, one left
const int KNIGHT_DOWN_RIGHT = 17;  // moves two squares down, one right
const int NUMBER_OF_MOVES = 8;

Knight::Knight(COLOURS pieceColour) : Piece(pieceColour, KNIGHT, false) {

	const int KNIHGT_MOVES[NUMBER_OF_MOVES] = {

		KNIGHT_UP_LEFT, 
		KNIGHT_UP_RIGHT, 
		KNIGHT_LEFT_UP, 
		KNIGHT_RIGHT_UP, 
		KNIGHT_LEFT_DOWN,
		KNIGHT_DOWN_RIGHT, 
		KNIGHT_DOWN_LEFT, 
		KNIGHT_DOWN_RIGHT 

	};

}