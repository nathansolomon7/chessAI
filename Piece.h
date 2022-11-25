#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
    
            std::string symbol;
            int value;
            int color;
            int PieceType;
            // generate moves for this specific piece
            Piece initializePiece(std::string symbol, int value, int color);

    private:
    
};

#endif