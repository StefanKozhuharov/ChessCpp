#pragma once
#include "constants.h"

class Piece {

private:

	COLOURS pieceColour; //stores the colour of the piece (black/white)
	PIECES pieceType; //stores the type of the piece (pawn, king, knight etc.)
	bool canCastle;
	const wchar_t* visualizationCode; //stores the code behind the visualization for the piece in the console
	void updateVisualizationCode(); //sets the square to the appropriate piece or leaves it empty

public:

	Piece();
	Piece(COLOURS pieceColour, PIECES pieceType, bool canCastle);
	virtual ~Piece() = default;

	COLOURS getPieceColour() const;
	PIECES getPieceType() const;
	bool getCanCastle() const;
	const wchar_t* getVisualizationCode() const;

	void setPieceColour(COLOURS pieceColour);
	void setPieceType(PIECES pieceType);
	void setCanCastle(bool canCastle);

	bool isEmpty() const;

	bool isLegalMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]); //checks rules that every piece needs to follow

	virtual bool canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]); //checks if a specific piece can move to attack an enemy piece
	virtual bool canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]); //checks if a specific piece can move to an empty square
	virtual bool isValidOffset(int currentPosition, int candidateOffset);

};