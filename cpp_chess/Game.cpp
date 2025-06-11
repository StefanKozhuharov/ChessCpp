#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include <iostream>
#include "utils.h"

using namespace std;

void Game::startGame() {

	COLOURS playerColour = WHITE;

	board.printBoard(playerColour);

	while (true) {
		
		wcout << (playerColour == WHITE) ? L"White's move: " : L"Black's move: ";

		char moveFrom[2], moveTo[2];
		cin >> moveFrom >> moveTo;

		int currentPosition = getCoordinates(moveFrom), destination = getCoordinates(moveTo);

		if (currentPosition < 0 || currentPosition >= BOARD_SIZE * BOARD_SIZE) {

			wcout << L"Incorrect data. Enter a valid starting coordinate.";
			continue;

		}

		Piece* currentPiece = board.getBoard()[currentPosition];

		if (!currentPiece->isLegalMove(currentPosition, destination, board.getBoard())) {

			wcout << L"Invalid move.";
			continue;

		}

		Piece* destinationPiece = board.getBoard()[destination];

		board.getBoard()[destination] = board.getBoard()[currentPosition];
		board.getBoard()[currentPosition] = new Piece();

		if (isCheck(board.getBoard(), getKingPosition(playerColour, board.getBoard()))) {

			delete board.getBoard()[currentPosition];
			board.getBoard()[currentPosition] = board.getBoard()[destination];
			board.getBoard()[destination] = destinationPiece;

			wcout << L"Invalid move. Your king will be in check!";

			continue;

		}

		delete board.getBoard()[currentPosition];
		board.getBoard()[currentPosition] = board.getBoard()[destination];
		board.getBoard()[destination] = destinationPiece;

		executeMove(currentPosition, destination);

		if (playerColour == WHITE) {

			playerColour = BLACK;

		}
		else {

			playerColour = WHITE;

		}

		board.printBoard(playerColour);

	}

	//TODO ending the game and saving

}

int Game::getCoordinates(char coordinate[2]) {

	return (coordinate[1] - 'a') + (coordinate[2] - '0') * BOARD_SIZE;

}

void Game::executeMove(int currentPosition, int destination) {

	delete board.getBoard()[destination];
	board.getBoard()[destination] = board.getBoard()[currentPosition];
	board.getBoard()[currentPosition] = new Piece();
	board.getBoard()[destination]->setHasMoved(true);

}