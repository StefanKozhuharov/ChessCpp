#pragma once

const enum PIECES {

	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN

};

const wchar_t* WHITE_PIECES[] = {

	L"\u2654", //king
	L"\u2655" //queen
	L"\u2656", //rook
	L"\u2657", //bishop
	L"\u2658", //knight
	L"\u2659" //pawn

};

const wchar_t* BLACK_PIECES[] = {

	L"\u265A", //king
	L"\u265B", //queen
	L"\u265C", //rook
	L"\u265D", //bishop
	L"\u265E", //knight
	L"\u265F" //pawn

};

const int WHITE_COLOUR = 15;
const int BLACK_COLOUR = 0;
const int LIGHT_GRAY = 7;
const int RED = 4;