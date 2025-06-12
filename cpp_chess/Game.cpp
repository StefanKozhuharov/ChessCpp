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
		int candidateOffset = destination - currentPosition;

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

		for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

			board.getBoard()[i]->setCanEnPassantLeft(false);
			board.getBoard()[i]->setCanEnPassantRight(false);

		}

		if (currentPiece->getPieceType() == PAWN && candidateOffset % TWO_TOP == 0) {

			if (playerColour == WHITE) {

				board.getBoard()[destination + 1]->setCanEnPassantRight(true);
				board.getBoard()[destination - 1]->setCanEnPassantLeft(true);

			}
			else {

				board.getBoard()[destination - 1]->setCanEnPassantRight(true);
				board.getBoard()[destination + 1]->setCanEnPassantLeft(true); //NEEDS TO BE TESTED!!!!

			}

		}

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