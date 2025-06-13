#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "utils.h"

using namespace std;

void Game::startGame() {

	COLOURS playerColour = WHITE;
	bool canLoad = true;

	board.printBoard(playerColour);

	while (true) {
		
		wcout << ((playerColour == WHITE) ? L"White's move: " : L"Black's move: ");

		char option[255], moveFrom[255], moveTo[255];
		cin >> option;

		if (!strcmp(option, "save")) {

			saveGame(playerColour);
			return;
			
		}

		if (!strcmp(option, "load") && canLoad) {

			canLoad = false;
			loadGame(playerColour);
			board.printBoard(playerColour);
			continue;

		}
		
		if (!strcmp(option, "load") && !canLoad) {

			wcout << "Can not load" << endl;
			continue;

		}

		moveFrom[0] = option[0];
		moveFrom[1] = option[1];

		cin >> moveTo;

		int currentPosition = getCoordinates(moveFrom), destination = getCoordinates(moveTo);
		int candidateOffset = destination - currentPosition;

		if (currentPosition < 0 || currentPosition >= BOARD_SIZE * BOARD_SIZE) {

			wcout << L"Incorrect data. Enter a valid starting coordinate." << endl;
			continue;

		}

		Piece* currentPiece = board.getBoard()[currentPosition];

		if (!currentPiece->isLegalMove(currentPosition, destination, board.getBoard())) {

			wcout << L"Invalid move." << endl;
			continue;

		}

		Piece* destinationPiece = board.getBoard()[destination];

		board.getBoard()[destination] = board.getBoard()[currentPosition];
		board.getBoard()[currentPosition] = new Piece();

		if (isCheck(board.getBoard(), getKingPosition(playerColour, board.getBoard()))) {

			delete board.getBoard()[currentPosition];
			board.getBoard()[currentPosition] = board.getBoard()[destination];
			board.getBoard()[destination] = destinationPiece;

			wcout << L"Invalid move. Your king will be in check!" << endl;

			continue;

		}

		delete board.getBoard()[currentPosition];
		board.getBoard()[currentPosition] = board.getBoard()[destination];
		board.getBoard()[destination] = destinationPiece;

		setEnPassant();

		if (currentPiece->getPieceType() == PAWN && candidateOffset % TWO_TOP == 0) {

			if (playerColour == WHITE) {

				board.getBoard()[destination + 1]->setCanEnPassantRight(true);
				board.getBoard()[destination - 1]->setCanEnPassantLeft(true);

			}
			else {

				board.getBoard()[destination - 1]->setCanEnPassantRight(true);
				board.getBoard()[destination + 1]->setCanEnPassantLeft(true);

			}

		}

		int r = (currentPosition / 8) * 8, c = destination % 8;

		if (currentPiece->getPieceType() == PAWN && (candidateOffset % TOP_LEFT == 0 || candidateOffset % TOP_RIGHT == 0) && board.getBoard()[destination]->isEmpty()) {

			delete board.getBoard()[r + c];
			board.getBoard()[r + c] = new Piece();

		}

		if (currentPiece->getPieceType() == KING && candidateOffset % TWO_LEFT == 0) {

			if (candidateOffset == TWO_LEFT) {

				delete board.getBoard()[r + 3];
				board.getBoard()[r + 3] = board.getBoard()[r];
				board.getBoard()[r] = new Piece();

			}

			if (candidateOffset == TWO_RIGHT) {

				delete board.getBoard()[r + 5];
				board.getBoard()[r + 5] = board.getBoard()[r + 7];
				board.getBoard()[r + 7] = new Piece();

			}

		}

		executeMove(currentPosition, destination);

		int promotionRank = playerColour == WHITE ? 0 : 7;

		while (board.getBoard()[destination]->getPieceType() == PAWN && destination / 8 == promotionRank) {

			wcout << "What would you like your pawn to turn into? (k - knight, r - rook, b - bishop, q - queen): ";
			char promotionPiece;
			cin >> promotionPiece;

			switch (promotionPiece) {

			case 'k':

				delete board.getBoard()[destination];
				board.getBoard()[destination] = new Knight(playerColour);
				break;

			case 'r':

				delete board.getBoard()[destination];
				board.getBoard()[destination] = new Rook(playerColour);
				break;

			case 'b':

				delete board.getBoard()[destination];
				board.getBoard()[destination] = new Bishop(playerColour);
				break;

			case 'q':

				delete board.getBoard()[destination];
				board.getBoard()[destination] = new Queen(playerColour);
				break;

			default:

				wcout << "Invalid piece." << endl;
				break;

			}

		}

		if (playerColour == WHITE) {

			playerColour = BLACK;

		}
		else {

			playerColour = WHITE;

		}

		board.printBoard(playerColour);

		canLoad = false;

	}

}

int Game::getCoordinates(char coordinate[2]) {

	return (coordinate[0] - 'a') + (BOARD_SIZE - (coordinate[1] - '1') - 1) * BOARD_SIZE;

}

void Game::executeMove(int currentPosition, int destination) {

	delete board.getBoard()[destination];
	board.getBoard()[destination] = board.getBoard()[currentPosition];
	board.getBoard()[currentPosition] = new Piece();
	board.getBoard()[destination]->setHasMoved(true);

}

void Game::setEnPassant() {

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		board.getBoard()[i]->setCanEnPassantLeft(false);
		board.getBoard()[i]->setCanEnPassantRight(false);

	}

}

void Game::saveGame(COLOURS playerColour) {

	ofstream outFile(fileName, ios::binary);

	if (!outFile) {

		throw runtime_error("Could not open save file.");

	}

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

			Piece* piece = board.getBoard()[i];
			PIECES pieceType = piece->getPieceType();
			COLOURS pieceColour = piece->getPieceColour();
			bool hasMoved = piece->getHasMoved();
			bool canEnPassantLeft = piece->getCanEnPassantLeft();
			bool canEnPassantRight = piece->getCanEnPassantRight();

			outFile.write(reinterpret_cast<const char*>(&pieceType), sizeof(int));
			outFile.write(reinterpret_cast<const char*>(&pieceColour), sizeof(int));
			outFile.write(reinterpret_cast<const char*>(&hasMoved), sizeof(bool));
			outFile.write(reinterpret_cast<const char*>(&canEnPassantLeft), sizeof(bool));
			outFile.write(reinterpret_cast<const char*>(&canEnPassantRight), sizeof(bool));

	}

	outFile.write(reinterpret_cast<const char*>(&playerColour), sizeof(int));

	outFile.close();

}

void Game::loadGame(COLOURS& playerColour) {

	ifstream inFile(fileName, ios::binary);

	if (!inFile) {

		throw runtime_error("Could not open save file.");

	}

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		PIECES pieceType;
		COLOURS pieceColour;
		bool hasMoved;
		bool canEnPassantLeft;
		bool canEnPassantRight;

		inFile.read(reinterpret_cast<char*>(&pieceType), sizeof(int));
		inFile.read(reinterpret_cast<char*>(&pieceColour), sizeof(int));
		inFile.read(reinterpret_cast<char*>(&hasMoved), sizeof(bool));
		inFile.read(reinterpret_cast<char*>(&canEnPassantLeft), sizeof(bool));
		inFile.read(reinterpret_cast<char*>(&canEnPassantRight), sizeof(bool));

		delete board.getBoard()[i];

		switch (pieceType) {

		case EMPTY:

			board.getBoard()[i] = new Piece();
			break;

		case KING:

			board.getBoard()[i] = new King(pieceColour);
			break;

		case QUEEN:

			board.getBoard()[i] = new Queen(pieceColour);
			break;

		case ROOK:

			board.getBoard()[i] = new Rook(pieceColour);
			break;

		case BISHOP:

			board.getBoard()[i] = new Bishop(pieceColour);
			break;

		case KNIGHT:

			board.getBoard()[i] = new Knight(pieceColour);
			break;

		case PAWN:

			board.getBoard()[i] = new Pawn(pieceColour);
			break;

		}

		board.getBoard()[i]->setHasMoved(hasMoved);
		board.getBoard()[i]->setCanEnPassantLeft(canEnPassantLeft);
		board.getBoard()[i]->setCanEnPassantRight(canEnPassantRight);

	}

	inFile.read(reinterpret_cast<char*>(&playerColour), sizeof(int));

	inFile.close();

}