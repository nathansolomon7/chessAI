#include <iostream>
#include "chessBoard.h"
#include <string>
using namespace std;


int main() {
    ChessBoard Board;
    string prevMove = "text";
    string nextMove = "text";
    Board.initializeBoard();
    Board.printBoard();
    int turn = 1;
    int WHITE_TURN = 0;
    int BLACK_TURN = 1;
    while (prevMove != "quit" and nextMove != "quit") {
        if (turn % 2 != 0) {
            Board.currColorTurn = WHITE_TURN;
            cout << "white's move: " << endl;
        }
        else {
            Board.currColorTurn = BLACK_TURN;
            cout << "black's move: " << endl;
        }
        cin >> prevMove >> nextMove;
        cout << prevMove << " -> " << nextMove << endl;
        if (!Board.movePiece(prevMove, nextMove)) {
            continue;
        }
        Board.printBoard();
        turn++;
    }
    
    return 0;
}
