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

const enum COLOURS {

	NONE = -1,
	BLACK = 0,
	WHITE = 1

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

const wchar_t* WHITE_PIECES[] = {

	L"\u2654", //king - 0 same as the type
	L"\u2655" //queen - 1 same as the type
	L"\u2656", //rook - 2 same as the type
	L"\u2657", //bishop - 3 same as the type
	L"\u2658", //knight - 4 same as the type
	L"\u2659" //pawn - 5 same as the type

};

const wchar_t* BLACK_PIECES[] = {

	L"\u265A", //king - 0 same as the type
	L"\u265B", //queen - 1 same as the type
	L"\u265C", //rook - 2 same as the type
	L"\u265D", //bishop - 3 same as the type
	L"\u265E", //knight - 4 same as the type
	L"\u265F" //pawn - 5 same as the type

};

const int WHITE_COLOUR = 15;
const int BLACK_COLOUR = 0;
const int LIGHT_GRAY = 7;
const int RED = 4;