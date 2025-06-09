#include <iostream>
#include "Piece.h"
#include "constants.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Board.h"

using namespace std;

void Board::setupPawns(COLOURS pieceColour, int row) {

	for (size_t i = 0; i < BOARD_SIZE; i++) {

		board[row * BOARD_SIZE + i] = new Pawn(pieceColour);

	}

}

void Board::setupBackRank(COLOURS pieceColour, int row) {

	board[row * BOARD_SIZE + 0] = new Rook(pieceColour);
	board[row * BOARD_SIZE + 1] = new Knight(pieceColour);
	board[row * BOARD_SIZE + 2] = new Bishop(pieceColour);
	board[row * BOARD_SIZE + 3] = new Queen(pieceColour);
	board[row * BOARD_SIZE + 4] = new King(pieceColour);
	board[row * BOARD_SIZE + 5] = new Bishop(pieceColour);
	board[row * BOARD_SIZE + 6] = new Knight(pieceColour);
	board[row * BOARD_SIZE + 7] = new Rook(pieceColour);

}

Piece** Board::getBoard() {

	return board;

}

void Board::printBoard() {

	//TODO: printing the board

}