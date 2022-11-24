// #ifndef CHESS_BOARD_H
// #define CHESS_BOARD_H
class ChessBoard {
    public:
        ChessBoard();
        ~ChessBoard();
        void initializeBoard();
        void movePiece(std::string start, std::string end);
    private:
    std::string board[8][8];
};


// #endif



