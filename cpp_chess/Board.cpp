#include <iostream>
#include <windows.h>
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

	wcout << L"\033[2J\033[H\033[3J";

	int bgColour = RED;

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		if ((i + i / 8) % 2 == 0) {

			bgColour = DARK_GRAY;

		}
		else {

			bgColour = RED;

		}


		if (i % 8 == 0) {

			resetColour();

			if (playerColour == BLACK) {

				wcout << i / 8 + 1 << " ";

			}
			else {

				wcout << (BOARD_SIZE * BOARD_SIZE - i) / 8 << " ";

			}

		}

		Piece* currentPiece = playerColour == WHITE ? board[i] : board[BOARD_SIZE * BOARD_SIZE - i - 1];

		setColour(currentPiece->getPieceColour(), bgColour);
		wcout << currentPiece->getVisualizationCode() << " ";

		if ((i + 1) % 8 == 0) {

			resetColour();
			wcout << endl;

		}

	}

	resetColour();
	wcout << "  ";

	for (size_t i = 0; i < BOARD_SIZE; i++) {

		char character;

		if (playerColour == BLACK) {

			character = 'h' - i;

		}
		else {

			character = 'a' + i;

		}

		wcout << character << " ";

	}

	resetColour();
	wcout << endl << endl;

}

void Board::setColour(int textColour, int bgColour) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textColour + (bgColour << 4));

}

void Board::resetColour() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE + (BLACK << 4));

}