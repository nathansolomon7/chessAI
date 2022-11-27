#include <iostream>
#include <string>
#include <assert.h>
#include "chessBoard.h"
using namespace std;
int main() {
    ChessBoard Board;
    assert(Board.convertStringInputToChessCoord("a1") == 0);
    return 0;
}