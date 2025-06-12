#pragma once

bool isFirstColumn(int currentPosition);
bool isSecondColumn(int currentPosition);
bool isSeventhColumn(int currentPosition);
bool isEighthColumn(int currentPosition);

int getKingPosition(COLOURS pieceColour, Piece* board[BOARD_SIZE * BOARD_SIZE]);

bool isCheck(Piece* board[BOARD_SIZE * BOARD_SIZE], int kingPosition);

bool isPathClear(int currentPosition, int candidateOffset, int repititions, Piece* board[BOARD_SIZE * BOARD_SIZE]);