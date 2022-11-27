#ifndef PIECE_H
#define PIECE_H
#include <vector>
class Piece {
    public:

            // Piece(std::string s, int v, int c, int p, bool isSliding);
            std::string symbol;
            int value;
            int color;
            int type;
            bool isSlidingPiece;
            bool isAtStartingPosition;
            // generate moves for this specific piece
            // Piece initializePiece(std::string symbol, int value, int color, int pieceType);
            // std::vector<int> getMoves(int currRow, int currCol, Piece (*board)[8][8], int playerColor);

    private:
    
};

#endif