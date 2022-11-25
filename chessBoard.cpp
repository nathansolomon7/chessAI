#include <iostream>
#include "chessBoard.h"
#include "Piece.h"
using namespace std;

string BLACK_KING   = "\u2654";
string BLACK_QUEEN	= "\u2655";
string BLACK_ROOK   = "\u2656";	
string BLACK_BISHOP = "\u2657";
string BLACK_KNIGHT = "\u2658";
string BLACK_PAWN	= "\u2659";


string WHITE_KING	= "\u265A";
string WHITE_QUEEN	= "\u265B";
string WHITE_ROOK	= "\u265C";	
string WHITE_BISHOP	= "\u265D";	
string WHITE_KNIGHT	= "\u265E";
string WHITE_PAWN	= "\u265F";	
int WHITE = 1;
int BLACK = 0;
enum {
    ROOK = 0,
    KNIGHT,
    BISHOP,
    KING,
    QUEEN,
    PAWN
};

int rowNumtoBoard[9] = {-1, 7, 6, 5, 4, 3, 2, 1, 0};
 ChessBoard::ChessBoard(){
    
}

 ChessBoard::~ChessBoard(){
    
}

void ChessBoard::initializeBoard() {
    // intialize white pieces
    board[7][0] = initializePiece(WHITE_ROOK, 5, 1, ROOK);
    board[7][1] = initializePiece(WHITE_KNIGHT, 3, 1, KNIGHT);
    board[7][2] = initializePiece(WHITE_BISHOP, 3, 1, BISHOP);
    board[7][3] = initializePiece(WHITE_QUEEN, 9, 1, QUEEN);
    board[7][4] = initializePiece(WHITE_KING, 90, 1, KING);
    board[7][5] = initializePiece(WHITE_BISHOP, 3, 1, BISHOP);
    board[7][6] = initializePiece(WHITE_KNIGHT, 3, 1, KNIGHT);
    board[7][7] = initializePiece(WHITE_ROOK, 5, 1, ROOK);
    // intialize white pawns
    board[6][0] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][1] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][2] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][3] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][4] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][5] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][6] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    board[6][7] = initializePiece(WHITE_PAWN, 1, 1, PAWN);
    // intialize black pawns
    board[1][0] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
    board[1][1] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
    board[1][2] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
    board[1][3] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
    board[1][4] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
    board[1][5] = initializePiece(BLACK_PAWN, -1, 0,PAWN);
    board[1][6] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
    board[1][7] = initializePiece(BLACK_PAWN, -1, 0, PAWN);
     // intialize black pieces
    board[0][0] = initializePiece(BLACK_ROOK, -5, 0, ROOK);
    board[0][1] = initializePiece(BLACK_KNIGHT, -3, 0, KNIGHT);
    board[0][2] = initializePiece(BLACK_BISHOP, -3, 0, BISHOP);
    board[0][3] = initializePiece(BLACK_QUEEN, -9, 0, QUEEN);
    board[0][4] = initializePiece(BLACK_KING, -90, 0, KING);
    board[0][5] = initializePiece(BLACK_BISHOP, -3, 0, BISHOP);
    board[0][6] = initializePiece(BLACK_KNIGHT, -3, 0, KNIGHT);
    board[0][7] = initializePiece(BLACK_ROOK, -5, 0, ROOK);


     for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].symbol = ".";
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

bool ChessBoard::movePiece(string start, string end) {
    if (!isValidInput(start, end) ) {
            cout << "not a valid move" << endl;
            return false;
    }
   int currPosition[2];
   int nextPosition[2];
   getPosition(start, currPosition);
   getPosition(end, nextPosition);
   // piece we are trying to move
   Piece currPiece = board[currPosition[0]][currPosition[1]];
   if(!isValidMove(currPiece.color, nextPosition[0], nextPosition[1])) {
        return false;
   }
   // replace piece with empty space, as you have just moved it
   board[currPosition[0]][currPosition[1]].symbol = ".";
   // move the piece we are trying to move to its new location
   board[nextPosition[0]][nextPosition[1]] = currPiece;
   return true;
}

bool ChessBoard::isValidInput(string start, string end) {
     if (start[0] > 'H' or start[0] < 'A' 
    or start[1] > '8' or start[1] < '1'  or
    end[0] > 'H' or end[0] < 'A' 
    or end[1] > '8' or end[1] < '1'  ) {
            return false;
    }
    return true;
}

void ChessBoard::printBoard() {
    int z = 8;
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << z << " ";
        for (int j = 0; j < 8; j++) {
           cout << board[i][j].symbol << "  ";
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

Piece ChessBoard::initializePiece(string symbol, int value, int color, int pieceType) {
    Piece newPiece;
    newPiece.symbol = symbol;
    newPiece.value = value;
    newPiece.color = color;
    newPiece.PieceType = pieceType;
    return newPiece;
}

bool ChessBoard::isValidMove(int prevColor, int nextRow, int nextCol) {
    if (board[nextRow][nextCol].color == prevColor or nextRow < 0 or nextRow > 7 or nextCol < 0 or nextCol > 7) {
        cout << "not a valid move" << endl;
        return false;
    }
    return true;
}








