#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "utils.h"

using namespace std;

void Game::startGame() {

	COLOURS playerColour = WHITE; //sets the player turn to white at the start of the game
	bool canLoad = true; //gives the ability to load a previous game at the start of a new game

	board.printBoard(playerColour); //prints the board
	saveBoardState(); //saves the starting board state

	while (true) {

		if (isWin(playerColour)) { //checks if the player whose turn it is is in mate

			wcout << ((playerColour == WHITE) ? L"Black has won! " : L"White has won! ");
			return;

		}

		if (isDraw(playerColour)) { //checks if the player whose turn it is is not in mate but has no legal moves

			wcout << "It's a draw!";
			return;

		}
		
		wcout << ((playerColour == WHITE) ? L"White's move: " : L"Black's move: ");

		char option[255], moveFrom[255], moveTo[255];
		cin >> option; //gives the player the option to choose to save their game, load a previous game or make a move

		if (!strcmp(option, "save")) {

			saveGame(playerColour); //saves the game
			return;
			
		}

		if (!strcmp(option, "load") && canLoad) {

			canLoad = false; //prevents future loading after doing it once
			loadGame(playerColour); //loads the game
			board.printBoard(playerColour); //prints the new board taken from the saved game
			continue;

		}
		
		if (!strcmp(option, "load") && !canLoad) { //prevents loading more than once or after a move has already been made

			wcout << "Can not load" << endl;
			continue;

		}

		moveFrom[0] = option[0];
		moveFrom[1] = option[1];

		cin >> moveTo;

		int currentPosition = getCoordinates(moveFrom), destination = getCoordinates(moveTo);
		int candidateOffset = destination - currentPosition;

		if (currentPosition < 0 || currentPosition >= BOARD_SIZE * BOARD_SIZE) { //checks if the player has entered coordinates that are valid

			wcout << L"Incorrect data. Enter a valid starting coordinate." << endl;
			continue;

		}

		Piece* currentPiece = board.getBoard()[currentPosition];

		if (!currentPiece->isLegalMove(currentPosition, destination, board.getBoard())) { //checks if the wanted move is legal

			wcout << L"Invalid move." << endl;
			continue;

		}

		if (!isKingSafe(playerColour, currentPosition, destination)) { //prevents a move that will leave the king in danger

			wcout << "Invalid move. Your king will be in check!" << endl;
			continue;

		}

		setEnPassant(); //resets the possibility of every piece's ability to en passant to false

		if (currentPiece->getPieceType() == PAWN && candidateOffset % TWO_TOP == 0) { //checks if a pawn has moved in a way that enables en passant

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

		//deletes the pawn where en passant was executed

		if (currentPiece->getPieceType() == PAWN && (candidateOffset % TOP_LEFT == 0 || candidateOffset % TOP_RIGHT == 0) && board.getBoard()[destination]->isEmpty()) { 

			delete board.getBoard()[r + c];
			board.getBoard()[r + c] = new Piece();

		}

		if (currentPiece->getPieceType() == KING && candidateOffset % TWO_LEFT == 0) { //performs a castle

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

		if (currentPiece->getPieceType() == PAWN || !board.getBoard()[destination]->isEmpty()) { //resets the currentSavedBoardState counter if either a pawn is moving or a piece has been taken

			currentSavedBoardState = 0;

		}

		executeMove(currentPosition, destination); //executes the wanted move

		int promotionRank = playerColour == WHITE ? 0 : 7;

		while (board.getBoard()[destination]->getPieceType() == PAWN && destination / 8 == promotionRank) { //check for pawn promotion

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

		if (playerColour == WHITE) { //changes whose turn it is

			playerColour = BLACK;

		}
		else {

			playerColour = WHITE;

		}

		board.printBoard(playerColour); //prints the new board after the move has been executed

		canLoad = false; //prevents loading a previous game after a move has been made
		saveBoardState(); //saves the new board state

	}

}

int Game::getCoordinates(char coordinate[2]) { //transforms the coordinates given by the player into an integer

	if (coordinate[0] >= 'a' && coordinate[0] <= 'h' && coordinate[1] >= '1' && coordinate[1] <= '8') {

		return (coordinate[0] - 'a') + (BOARD_SIZE - (coordinate[1] - '1') - 1) * BOARD_SIZE;

	}

	return -1;

}

void Game::executeMove(int currentPosition, int destination) { 

	delete board.getBoard()[destination]; //releases the data of the destination square
	board.getBoard()[destination] = board.getBoard()[currentPosition]; //sets the destination square to the one from the starting position
	board.getBoard()[currentPosition] = new Piece(); //sets the starting position to an empty square
	board.getBoard()[destination]->setHasMoved(true); //remembers that the piece has moved

}

void Game::setEnPassant() { //sets every piece of the board's ability to en passant to false

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		board.getBoard()[i]->setCanEnPassantLeft(false);
		board.getBoard()[i]->setCanEnPassantRight(false);

	}

}

void Game::saveGame(COLOURS playerColour) { //saves the state of the board as well as every characteristic a piece on it has and also which player is supposed to play next

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

void Game::loadGame(COLOURS& playerColour) { //loads the saved game 

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

		delete board.getBoard()[i]; //deletes the starting board that is made when the game starts

		switch (pieceType) { //changes it to the appropriate piece

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

bool Game::isWin(COLOURS playerColour) { //checks wether the player whose turn it is has lost

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		Piece* currentPiece = board.getBoard()[i];

		if (currentPiece->getPieceColour() == playerColour && hasLegalMoves(currentPiece, i)) { //checks if a piece the player has has any legal move

			return false;

		}

	}

	return isCheck(board.getBoard(), getKingPosition(playerColour, board.getBoard())); //returns true if the player is in check ending the game and false and continuing the game if not

}

bool Game::isDraw(COLOURS playerColour) { //checks wether the game is a draw

	int sum = 0; //how many turns have gone without a pawn being moved or a piece being taken

	for (size_t i = 0; i < currentSavedBoardState; i++) {

		if (numberOfRepetitionsOfBoardState[i] >= 3) { //checks if we've reached a three fold repetition

			return true;

		}

		sum += numberOfRepetitionsOfBoardState[i]; //adds the number of times we've seen the current board state

	}

	if (sum >= 50) { //checks if we`ve had 50 turns without a pawn being moved or a piece being taken

		return true;

	}

	int numberOfBishops = 0, numberOfKnights = 0;

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		if (board.getBoard()[i]->getPieceType() == KNIGHT) { //checks if the current piece is a knight

			numberOfKnights++;

		}
		else if (board.getBoard()[i]->getPieceType() == BISHOP) { //checks if the current piece is a bishop

			numberOfBishops++;

		}
		else if (board.getBoard()[i]->getPieceType() == KING || board.getBoard()[i]->getPieceType() == EMPTY) { //checks if it's a king or an empty space

			continue;

		}
		else { //checks if it's any other piece

			numberOfKnights = 2; //prevents a draw from having only 1 bishop or only 1 knight on the board
			break;

		}

	}

	if (numberOfBishops + numberOfKnights <= 1) { //draws the game if there is only 1 bishop or only 1 knight on the board or no pieces other than the kings

		return true;

	}

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		Piece* currentPiece = board.getBoard()[i];

		if (currentPiece->getPieceColour() == playerColour && hasLegalMoves(currentPiece, i)) { //checks if any piece has a legal move

			return false;

		}

	}

	return !isCheck(board.getBoard(), getKingPosition(playerColour, board.getBoard())); //return true if the king isn't in check and false if it is

}

bool Game::hasLegalMoves(Piece* piece, int currentPosition) { //checks if a piece has any legal moves

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

		if (piece->isLegalMove(currentPosition, i, board.getBoard()) && isKingSafe(piece->getPieceColour(), currentPosition, i)) {

			return true;

		}

	}

	return false;

}

void Game::saveBoardState() { //saves the current board state and how many times it has been seen

	char boardState[BOARD_SIZE * BOARD_SIZE + 1];

	for (size_t i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {

			Piece* piece = board.getBoard()[i];
			char symbol = piece->getPieceType() + 1;
			boardState[i] = piece->getPieceColour() == WHITE ? symbol : symbol + BOARD_SIZE;

	}

	boardState[BOARD_SIZE * BOARD_SIZE] = '\0';

	for (size_t i = 0; i < currentSavedBoardState; i++) {

		if (!strcmp(boardState, previousBoards[i])) {

			numberOfRepetitionsOfBoardState[i]++;
			return;

		}

	}

	strcpy_s(previousBoards[currentSavedBoardState], BOARD_SIZE * BOARD_SIZE + 1, boardState);
	numberOfRepetitionsOfBoardState[currentSavedBoardState] = 1;
	currentSavedBoardState++;

}

bool Game::isKingSafe(COLOURS playerColour, int currentPosition, int destination) { //checks if the king is safe by artificaly executing the move

	Piece* destinationPiece = board.getBoard()[destination];
	board.getBoard()[destination] = board.getBoard()[currentPosition];
	board.getBoard()[currentPosition] = new Piece();

	if (isCheck(board.getBoard(), getKingPosition(playerColour, board.getBoard()))) {

		delete board.getBoard()[currentPosition];
		board.getBoard()[currentPosition] = board.getBoard()[destination];
		board.getBoard()[destination] = destinationPiece;

		return false;

	}

	delete board.getBoard()[currentPosition];
	board.getBoard()[currentPosition] = board.getBoard()[destination];
	board.getBoard()[destination] = destinationPiece;

	return true;

}