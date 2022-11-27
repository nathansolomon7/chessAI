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
    string oponnentMoveArr[2];
    while (prevMove != "quit" and nextMove != "quit") {
        if (turn % 2 != 0) {
            Board.currColorTurn = WHITE_TURN;
          
        }
        else {
            Board.currColorTurn = BLACK_TURN;
        }
        
        Board.generateMoves();
        // Board.printAllMoves();
        if (turn % 2 != 0) {
            cout << "white's move: " << endl;
             cin >> prevMove >> nextMove;
        }
        else {
            cout << "black's move: " << endl;
            Board.generateRandomOpponentMove(oponnentMoveArr);
            cout << "opponent " << oponnentMoveArr[0] << " -> " << oponnentMoveArr[1] << endl;
            if (!Board.movePiece(oponnentMoveArr[0], oponnentMoveArr[1])) {
                continue;
            }
            Board.printBoard();
            Board.clearMoveList();
            turn++;
            continue;
        }
       
        if(prevMove != "quit" and nextMove == "options") {
            Board.displayMovesForPiece(prevMove);
            continue;
        }
        cout << prevMove << " -> " << nextMove << endl;
        if (!Board.movePiece(prevMove, nextMove)) {
            continue;
        }
        Board.printBoard();
        Board.clearMoveList();
        turn++;
    }
    
    return 0;
}
