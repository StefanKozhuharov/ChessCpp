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

Board::Board() { //sets up the starting board

	setupBackRank(BLACK, 0);
	setupPawns(BLACK, 1);
	setupEmptySquares();
	setupPawns(WHITE, 6);
	setupBackRank(WHITE, 7);

}

void Board::setupPawns(COLOURS pieceColour, int row) { //sets up the pawns on row 2 and 7

	for (size_t i = 0; i < BOARD_SIZE; i++) {

		board[row * BOARD_SIZE + i] = new Pawn(pieceColour);

	}

}

void Board::setupBackRank(COLOURS pieceColour, int row) { //sets up the back rank of the white and black player

	board[row * BOARD_SIZE + 0] = new Rook(pieceColour);
	board[row * BOARD_SIZE + 1] = new Knight(pieceColour);
	board[row * BOARD_SIZE + 2] = new Bishop(pieceColour);
	board[row * BOARD_SIZE + 3] = new Queen(pieceColour);
	board[row * BOARD_SIZE + 4] = new King(pieceColour);
	board[row * BOARD_SIZE + 5] = new Bishop(pieceColour);
	board[row * BOARD_SIZE + 6] = new Knight(pieceColour);
	board[row * BOARD_SIZE + 7] = new Rook(pieceColour);

}

void Board::setupEmptySquares() { //sets all other squares as empty

	for (size_t i = 16; i < 48; i++) {

		board[i] = new Piece();

	}

}

Piece** Board::getBoard() { //returns the board

	return board;

}

void Board::printBoard(COLOURS playerColour) { //prints the board

	wcout << L"\033[2J\033[H\033[3J"; //deletes previous console messages

	int bgColour = RED;

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) { //sets up the colours of the board squares

		if ((i + i / 8) % 2 == 0) {

			bgColour = DARK_GRAY;

		}
		else {

			bgColour = RED;

		}


		if (i % 8 == 0) {

			resetColour();

			if (playerColour == BLACK) { //sets up the numbers next to the board for when the board is flipped for the black player

				wcout << i / 8 + 1 << " ";

			}
			else { //sets up the numbers next to the board for when the board is flipped for the white player

				wcout << (BOARD_SIZE * BOARD_SIZE - i) / 8 << " ";

			}

		}

		Piece* currentPiece = playerColour == WHITE ? board[i] : board[BOARD_SIZE * BOARD_SIZE - i - 1]; //gets the current piece if it's white's turn and the opposite if it's black's turn

		setColour(currentPiece->getPieceColour(), bgColour); //sets the colour of the piece
		wcout << currentPiece->getVisualizationCode() << " "; //prints the piece and the painted square

		if ((i + 1) % 8 == 0) { //adds a new line if we've reached the end of a row

			resetColour();
			wcout << endl;

		}

	}

	resetColour();
	wcout << "  "; //adds a space between each piece

	for (size_t i = 0; i < BOARD_SIZE; i++) { //sets up the characters below the board according to which player's turn it is

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

void Board::setColour(int textColour, int bgColour) { //sets the colour of a piece and the square behind it

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textColour + (bgColour << 4));

}

void Board::resetColour() { //resets the changes to the console colours we've made

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE + (BLACK << 4));

}