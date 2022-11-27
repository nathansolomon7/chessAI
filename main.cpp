#include <iostream>
#include "chessBoard.h"
#include <string>
#include <assert.h>
using namespace std;


int main() {
    ChessBoard Board;
    // assert(Board.convertStringInputToChessCoord("b1") == 1);
    // assert(Board.convertStringInputToChessCoord("b2") == 9);
    // assert(Board.convertStringInputToChessCoord("b3") == 17);
    // assert(Board.convertStringInputToChessCoord("b4") == 25);
    // assert(Board.convertStringInputToChessCoord("b5") == 33);
    // assert(Board.convertStringInputToChessCoord("b6") == 41);
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
        
        Board.generateMoves();
        Board.printAllMoves();
        if(prevMove != "quit" and nextMove == "options") {
            Board.displayMovesForPiece(prevMove);
            continue;
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
