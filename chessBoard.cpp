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

int rowNumtoBoard[9] = {-1, 7, 6, 5, 4, 3, 2, 1, 0};
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
}

int ChessBoard::getColCoord(char letter) {
    letter = tolower(letter);
    // cout << "col coordinate: " << letter - 97 << endl;
    return letter - 97;
}

int ChessBoard::getRowCoord(char number) {
    // input to board mapping
    int num = (int)(number - 48);
    // cout << "row coordinate: " << num << endl;
    // cout << "maps to " << rowNumtoBoard[num] << " in 2d array" << endl;
    return rowNumtoBoard[num];
}


void ChessBoard::getPosition(string currCoord, int* positionArr) {
    
    positionArr[0] = getRowCoord(currCoord[1]);
    positionArr[1] = getColCoord(currCoord[0]);
}

void ChessBoard::movePiece(string start, string end) {
   int currPosition[2];
   int nextPosition[2];
   getPosition(start, currPosition);
   getPosition(end, nextPosition);
   // piece we are trying to move
   string currPiece = board[currPosition[0]][currPosition[1]];
   // replace piece with empty space, as you have just moved it
   board[currPosition[0]][currPosition[1]] = ".";
   // move the piece we are trying to move to its new location
   board[nextPosition[0]][nextPosition[1]] = currPiece;
}

void ChessBoard::printBoard() {
    int z = 8;
    cout << endl;
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








