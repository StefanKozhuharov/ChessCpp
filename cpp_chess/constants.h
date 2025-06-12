#pragma once

const int BOARD_SIZE = 8;
const int ERROR_CODE = 99;

const int TOP_LEFT = -9;  // moves to the top left corner
const int TOP = -8;  // moves one square up
const int TOP_RIGHT = -7;  // moves to the top right corner
const int LEFT = -1;  // moves one square left
const int RIGHT = 1;  // moves one square right
const int BOTTOM_LEFT = 7;  // moves to the bottom left corner
const int BOTTOM = 8;  // moves one square down
const int BOTTOM_RIGHT = 9;  // moves to the bottom right corner
const int TWO_TOP = -16; //moves two squares up

const enum COLOURS {

	NONE = 7,
	BLACK = 0,
	WHITE = 15

};

const enum PIECES {

	EMPTY = -1,
	KING = 0,
	QUEEN = 1,
	ROOK = 2,
	BISHOP = 3,
	KNIGHT = 4,
	PAWN = 5

};

const int DARK_GRAY = 8;
const int RED = 4;