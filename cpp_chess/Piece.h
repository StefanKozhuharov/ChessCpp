#pragma once
#include "constants.h"

class Piece {

private:

	COLOURS pieceColour; //stores the colour of the piece (black/white)
	PIECES pieceType; //stores the type of the piece (pawn, king, knight etc.)
	const wchar_t* visualizationCode; //stores the code behind the visualization for the piece in the console
	void updateVisualizationCode(); //sets the square to the appropriate piece or leaves it empty
	virtual int* generateMoves(); //function to generate every move a piece can make

public:

	Piece();
	Piece(COLOURS pieceColour, PIECES pieceType); 
	virtual ~Piece() = default;

	COLOURS getPieceColour() const;
	PIECES getPieceType() const;
	const wchar_t* getVisualizationCode() const;

	void setPieceColour(COLOURS pieceColour);
	void setPieceType(PIECES pieceType);

	bool isEmpty() const;

};