#include <iostream>
#include "chessBoard.h"
using namespace std;

int main() {
    ChessBoard Board;
    Board.initializeBoard();
    Board.movePiece("A7", "A6");
    Board.printBoard();
    return 0;
}
