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

Board::Board() {

	setupBackRank(BLACK, 0);
	setupPawns(BLACK, 1);
	setupEmptySquares();
	setupPawns(WHITE, 6);
	setupBackRank(WHITE, 7);

}

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

void Board::setupEmptySquares() {

	for (size_t i = 16; i < 48; i++) {

		board[i] = new Piece();

	}

}

Piece** Board::getBoard() {

	return board;

}

void Board::printBoard(COLOURS playerColour) {

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		wcout << board[i]->getVisualizationCode() << " ";

		if ((i+1) % 8 == 0) {

			wcout << endl;

		}

	}

}