#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
class ChessBoard {
    public:

        ChessBoard();
        ~ChessBoard();
        void initializeBoard();
        void movePiece(std::string start, std::string end);
        void printBoard();

    private:
        struct Piece {
            std::string symbol;
            int value;
        };
        Piece board[8][8];
        void getPosition(std::string currCoord, int* positionArr);
        int getColCoord(char letter);
        int getRowCoord(char number);
        Piece intializePiece(std::string symbol, int value);
};


#endif



