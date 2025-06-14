#pragma once
#include "constants.h"

class Piece {

private:

	COLOURS pieceColour;
	PIECES pieceType;
	bool hasMoved;
	bool canEnPassantLeft;
	bool canEnPassantRight;
	const wchar_t* visualizationCode; 
	void updateVisualizationCode(); 

public:

	Piece();
	Piece(COLOURS pieceColour, PIECES pieceType);
	virtual ~Piece() = default;

	COLOURS getPieceColour() const;
	PIECES getPieceType() const;
	bool getHasMoved() const;
	bool getCanEnPassantLeft() const;
	bool getCanEnPassantRight() const;
	const wchar_t* getVisualizationCode() const;

	void setPieceColour(COLOURS pieceColour);
	void setPieceType(PIECES pieceType);
	void setHasMoved(bool hasMoved);
	void setCanEnPassantLeft(bool canEnPassantLeft);
	void setCanEnPassantRight(bool canEnPassantRight);

	bool isEmpty() const;

	bool isLegalMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]); 

	virtual bool canAttack(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]); 
	virtual bool canMove(int currentPosition, int destination, Piece* board[BOARD_SIZE * BOARD_SIZE]); 
	virtual bool isValidOffset(int currentPosition, int candidateOffset);

};