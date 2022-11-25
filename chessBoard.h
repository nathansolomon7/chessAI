#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Piece.h"
class ChessBoard {
    public:

        ChessBoard();
        ~ChessBoard();
        void initializeBoard();
        bool movePiece(std::string start, std::string end);
        void printBoard();

    private:
        Piece board[8][8];
        void getPosition(std::string currCoord, int* positionArr);
        int getColCoord(char letter);
        int getRowCoord(char number);
        Piece initializePiece(std::string symbol, int value, int color);
        bool isValidMove(int prevColor, int nextRow, int nextCol);
        bool isValidInput(std::string start, std::string end);
};


#endif