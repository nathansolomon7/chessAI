#include <iostream>
#include "chessBoard.h"
using namespace std;

int main() {
    ChessBoard Board;
    string prevMove = "text";
    string nextMove = "text";
    Board.initializeBoard();
    Board.printBoard();
    int turn = 1;
    while (prevMove != "quit" and nextMove != "quit") {
        if (turn % 2 != 0) {
            cout << "white's move: " << endl;
        }
        else {
            cout << "black's move: " << endl;
        }
        cin >> prevMove >> nextMove;
        cout << prevMove << " -> " << nextMove << endl;
        Board.movePiece(prevMove, nextMove);
        Board.printBoard();
        turn++;
    }
    
    return 0;
}
