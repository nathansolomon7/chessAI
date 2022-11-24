// #ifndef CHESS_BOARD_H
// #define CHESS_BOARD_H
class ChessBoard {
    public:
        ChessBoard();
        ~ChessBoard();
        void initializeBoard();
    private:
    std::string board[8][8];
};


// #endif



