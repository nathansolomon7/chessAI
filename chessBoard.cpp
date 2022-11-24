#include <iostream>
#include <string>
#include "chessBoard.h"
using namespace std;

string WHITE_KING   = "\u2654";
string WHITE_QUEEN	= "\u2655";
string WHITE_ROOK   = "\u2656";	
string WHITE_BISHOP = "\u2657";
string WHITE_KNIGHT = "\u2658";
string WHITE_PAWN	= "\u2659";


string BLACK_KING	= "\u265A";
string BLACK_QUEEN	= "\u265B";
string BLACK_ROOK	= "\u265C";	
string BLACK_BISHOP	= "\u265D";	
string BLACK_KNIGHT	= "\u265E";
string BLACK_PAWN	= "\u265F";	

 ChessBoard::ChessBoard(){
    
}

 ChessBoard::~ChessBoard(){
    
}

void ChessBoard::initializeBoard() {
    // intialize white pieces
    board[7][0] = WHITE_ROOK;
    board[7][1] = WHITE_KNIGHT;
    board[7][2] = WHITE_BISHOP;
    board[7][3] = WHITE_QUEEN;
    board[7][4] = WHITE_KING;
    board[7][5] = WHITE_BISHOP;
    board[7][6] = WHITE_KNIGHT;
    board[7][7] = WHITE_ROOK;
    // intialize white pawns
    board[6][0] = WHITE_PAWN;
    board[6][1] = WHITE_PAWN;
    board[6][2] = WHITE_PAWN;
    board[6][3] = WHITE_PAWN;
    board[6][4] = WHITE_PAWN;
    board[6][5] = WHITE_PAWN;
    board[6][6] = WHITE_PAWN;
    board[6][7] = WHITE_PAWN;
    // intialize black pawns
    board[1][0] = BLACK_PAWN;
    board[1][1] = BLACK_PAWN;
    board[1][2] = BLACK_PAWN;
    board[1][3] = BLACK_PAWN;
    board[1][4] = BLACK_PAWN;
    board[1][5] = BLACK_PAWN;
    board[1][6] = BLACK_PAWN;
    board[1][7] = BLACK_PAWN;
     // intialize black pieces
    board[0][0] = WHITE_ROOK;
    board[0][1] = WHITE_KNIGHT;
    board[0][2] = WHITE_BISHOP;
    board[0][3] = WHITE_QUEEN;
    board[0][4] = WHITE_KING;
    board[0][5] = WHITE_BISHOP;
    board[0][6] = WHITE_KNIGHT;
    board[0][7] = WHITE_ROOK;


     for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = ".";
        }
    }
   
    // print board
    int z = 8;
    for (int i = 0; i < 8; i++) {
        cout << z << " ";
        for (int j = 0; j < 8; j++) {
           cout << board[i][j] << "  ";
        }
        z--;
        cout << endl;
    }
     // print letter headers
     cout << "  ";
    for (int i = 65; i < 73; i++) {
        cout << (char)i;
        if(i != 104) {
            cout << "  ";
        }
    }
    cout << endl;
}

void ChessBoard::movePiece(string start, string end) {
    string currPiece = board[(int)(start[0] - 97)][(int)start[1]];
    board[(int)(end[0] - 97)][(int)end[1]] = currPiece;
    return;
}



