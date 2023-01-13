#include <iostream>
#include "chessBoard.h"
#include <string>
#include <assert.h>
using namespace std;

int main() {
    ChessBoard Board;
    string prevMove = "text";
    string nextMove = "text";
    Board.initializeBoard();
    Board.printBoard();
    int turn = 1;
    string oponnentMoveArr[2];
    Piece fillerBoard[8][8];
    Piece pieceTaken;
    // int currPointFiller = 0;
    while (prevMove != "quit" and nextMove != "quit") {
        if (turn % 2 != 0) {
            Board.currColorTurnGlobal = WHITE_TURN;
          
        }
        else {
            Board.currColorTurnGlobal = BLACK_TURN;
        }
        
        // Board.generateMoves();
        // Board.printAllMoves();
        if (turn % 2 != 0) {
            cout << "Input your move: " << endl;
            cin >> prevMove >> nextMove;
            // prevMove = "A2";
            // nextMove = "A4";
        }
        else {
            cout << "black's move: " << endl;
            // Board.generateRandomOpponentMove(oponnentMoveArr);
            bool isCheckmate = false;
            if(Board.generateBestMove(oponnentMoveArr) == -1) {
                isCheckmate = true;
            }
            cout << "AI moved " << oponnentMoveArr[0] << " -> " << oponnentMoveArr[1] << endl;

            if (!Board.movePiece(oponnentMoveArr[0], oponnentMoveArr[1], Board.board, Board.currColorTurnGlobal, pieceTaken)) {
                break;
            }
            Board.printBoard();

            if(Board.currColorTurnGlobal == BLACK_TURN) {
                Board.isPlayerInCheck(Board.board, WHITE_TURN);
            }
            else {
                Board.isPlayerInCheck(Board.board, BLACK_TURN);
            }

            if(isCheckmate) {
                return 0;
            }
            
            Board.clearMoveList();
            turn++;
            continue;
        }
       
        if(prevMove != "quit" and nextMove == "options") {
             Board.generateMoves(Board.board, Board.currColorTurnGlobal, Board.playerMoveList);
            if(Board.isPlayerInCheck(Board.board, Board.currColorTurnGlobal)) {
                Board.generateMovesToGetOutOfCheck(Board.board, Board.currColorTurnGlobal, Board.playerMoveList);
                // cout << "player move list size (accounting for check): " << Board.playerMoveList.size() << endl;
                // cout << "displaying all moves for player to get out of check" << endl;
                // Board.displayAllMoves(Board.playerMoveList, Board.board);
            }
    
            Board.displayMovesForPiece(prevMove);
            
            continue;
        }
        cout << "Your move: " << prevMove << " -> " << nextMove << endl;
        if (!Board.isMoveInMoveSet(Board.board, Board.currColorTurnGlobal, Board.playerMoveList, prevMove, nextMove) or !Board.movePiece(prevMove, nextMove, Board.board, Board.currColorTurnGlobal, pieceTaken)) {
            continue;
        }
        // Board.printBoard();
        Board.clearMoveList();
        turn++;
    }
    
    return 0;
}
