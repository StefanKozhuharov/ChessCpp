#pragma once
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"

class PieceFactory {

public:

    static Piece* createPiece(const PIECES pieceType, const COLOURS pieceColour) {

        if (pieceType == KING) {

            return new King(pieceColour);

        }

        if (pieceType == QUEEN) {

            return new Queen(pieceColour);

        }

        if (pieceType == ROOK) {

            return new Rook(pieceColour);

        }

        if (pieceType == KNIGHT) {

            return new Knight(pieceColour);

        }

        if (pieceType == BISHOP) {

            return new Bishop(pieceColour);

        }

        if (pieceType == PAWN) {

            return new Pawn(pieceColour);

        }

        if (pieceType == EMPTY) {

            return new Piece();

        }

        return nullptr;

    }

};