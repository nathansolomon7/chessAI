#include <iostream>
#include "chessBoard.h"
#include "Piece.h"
#include <unordered_map>
#include <utility>
#include <unordered_set>
using namespace std;
//TODO: make Piece object oriented
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

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int rowNumtoBoard[9] = {-1, 7, 6, 5, 4, 3, 2, 1, 0};
 ChessBoard::ChessBoard(){
    
}

 ChessBoard::~ChessBoard(){
    
}

void ChessBoard::initializeBoard() {
    // intialize white pieces
    board[7][0] = initializePiece(WHITE_ROOK, 5, 1, ROOK, true, true);
    board[7][1] = initializePiece(WHITE_KNIGHT, 3, 1, KNIGHT, false, true);
    board[7][2] = initializePiece(WHITE_BISHOP, 3, 1, BISHOP, true, true);
    board[7][3] = initializePiece(WHITE_QUEEN, 9, 1, QUEEN, true, true);
    board[7][4] = initializePiece(WHITE_KING, 90, 1, KING, false, true);
    board[7][5] = initializePiece(WHITE_BISHOP, 3, 1, BISHOP, true, true);
    board[7][6] = initializePiece(WHITE_KNIGHT, 3, 1, KNIGHT, false, true);
    board[7][7] = initializePiece(WHITE_ROOK, 5, 1, ROOK, true, true);
    // intialize white pawns
    board[6][0] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][1] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][2] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][3] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][4] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][5] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][6] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    board[6][7] = initializePiece(WHITE_PAWN, 1, 1, PAWN, false, true);
    // intialize black pawns
    board[1][0] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
    board[1][1] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
    board[1][2] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
    board[1][3] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
    board[1][4] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
    board[1][5] = initializePiece(BLACK_PAWN, -1, 0,PAWN, false, true);
    board[1][6] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
    board[1][7] = initializePiece(BLACK_PAWN, -1, 0, PAWN, false, true);
     // intialize black pieces
    board[0][0] = initializePiece(BLACK_ROOK, -5, 0, ROOK, true, true);
    board[0][1] = initializePiece(BLACK_KNIGHT, -3, 0, KNIGHT, false, true);
    board[0][2] = initializePiece(BLACK_BISHOP, -3, 0, BISHOP, true, true);
    board[0][3] = initializePiece(BLACK_QUEEN, -9, 0, QUEEN, true, true);
    board[0][4] = initializePiece(BLACK_KING, -90, 0, KING, false, true);
    board[0][5] = initializePiece(BLACK_BISHOP, -3, 0, BISHOP, true, true);
    board[0][6] = initializePiece(BLACK_KNIGHT, -3, 0, KNIGHT, false, true);
    board[0][7] = initializePiece(BLACK_ROOK, -5, 0, ROOK, true, true);


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

Piece ChessBoard::initializePiece(string symbol, int value, int color, int pieceType, bool isSlidingPiece, bool isAtStartingPosition) {
    Piece newPiece;
    newPiece.symbol = symbol;
    newPiece.value = value;
    newPiece.color = color;
    newPiece.type = pieceType;
    newPiece.isSlidingPiece = isSlidingPiece;
    newPiece.isAtStartingPosition = isAtStartingPosition;
    return newPiece;
}

bool ChessBoard::isValidMove(int prevColor, int nextRow, int nextCol) {
    if (board[nextRow][nextCol].color == prevColor or nextRow < 0 or nextRow > 7 or nextCol < 0 or nextCol > 7) {
        cout << "not a valid move" << endl;
        return false;
    }
    return true;
}

void ChessBoard::findNumSquaresToEdge() {
    numSquaresInfo s;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            s.numNorth = 7 - j;
            s.numSouth = j;
            s.numWest = i;
            s.numEast = 7 - i;
            s.numNorthWest = min(s.numNorth, s.numWest);
            s.numSouthEast = min(s.numSouth, s.numEast);
            s.numNorthEast = min(s.numNorth, s.numEast);
            s.numSouthWest = min(s.numSouth, s.numWest);
            numSquaresToEdgeArr[i][j] = s;
        }
    }
    s.directionsArr[0] = s.numNorth;
    s.directionsArr[1] = s.numSouth;
    s.directionsArr[2] = s.numWest;
    s.directionsArr[3] = s.numEast;
    s.directionsArr[4] = s.numNorthWest;
    s.directionsArr[5] = s.numSouthEast;
    s.directionsArr[6] = s.numNorthEast;
    s.directionsArr[7] = s.numSouthWest;

}

void ChessBoard::generateMoves() {
    initChessCoordToArrayCoord();
    pair<int, int> currMove;
   for (int i = 0; i < 64; i++) {
            currMove = chessCoordToArrayCoord[64];
            Piece p = board[currMove.first][currMove.second];
        if (p.color == currColorTurn and p.isSlidingPiece) {
            generateSlidingMoves(p, i, currMove.first, currMove.second);
        }
        if(p.color == currColorTurn and p.type == PAWN) {
            generatePawnMoves(p, i);
        }
        if(p.color == currColorTurn and p.type == KNIGHT) {
            generateKnightMoves(p, i);
        }
    }
}

void ChessBoard::initChessCoordToArrayCoord() {
    int index = 0;
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 7; j++) {
            chessCoordToArrayCoord[index] = make_pair(i, j);
        }
    }
}


void ChessBoard::generateSlidingMoves(Piece startingPiece, int startingSquare, int arrRow, int arrCol) {
        // for each direction
        // go through the squares in the current direction
        pair<int, int> targetArrCoords;
        int startDirIdx = 0;
        int endDirIdx = 8;
        if (startingPiece.type == BISHOP) {
            startDirIdx = 4;
        }
        if (startingPiece.type == ROOK) {
            endDirIdx = 4;
        }
        for(int i = startDirIdx; i < 8; i++) { 
            for(int j = endDirIdx; j < numSquaresToEdgeArr[arrRow][arrCol].directionsArr[i]; j++) {
                int targetSquare = startingSquare + slidingPieceOffestsArr[i] * (j + 1);
                targetArrCoords = chessCoordToArrayCoord[targetSquare];
                Piece pieceOnTargetSquare = board[targetArrCoords.first][targetArrCoords.second];

                if(pieceOnTargetSquare.color == startingPiece.color) {
                    break;
                }
                struct Move currMove;
                currMove.start = startingSquare;
                currMove.end = targetSquare;
                moveList.push_back(currMove);

                if (pieceOnTargetSquare.color != startingPiece.color) {
                    // enemy piece
                    break;
                }
            }
        }
}


void ChessBoard::generatePawnMoves(Piece startingPiece, int startingSquare) {
     pair<int, int> northWestCoords;
     pair<int, int> northEastCoords;
     pair <int, int> oneAheadCoords;
     pair <int, int> twoAheadCoords;
     int targetSquare;
    
       int pawnOffsetForward = 8;
       int pawnOffetNorthWest = 7;
       int pawnOffetNorthEast = 9;
       // looking one ahead
       if(startingSquare + pawnOffsetForward <= 64) {
         oneAheadCoords = chessCoordToArrayCoord[startingSquare + pawnOffsetForward];
       }
      
       // looking two ahead
       if(startingSquare + startingSquare + pawnOffsetForward <= 64) {
            twoAheadCoords = chessCoordToArrayCoord[startingSquare + pawnOffsetForward + pawnOffsetForward];
       }
       
        // looking northwest 
        if(startingSquare + pawnOffetNorthWest <= 64) {
            northWestCoords = chessCoordToArrayCoord[startingSquare + pawnOffetNorthWest];
        }
      
        if(startingSquare + pawnOffetNorthEast <= 64) {
            northEastCoords = chessCoordToArrayCoord[startingSquare + pawnOffetNorthEast];
        }
       
        // TODO: make sure no out of bounds occurs here
        // if the square one ahead is free
       if(board[oneAheadCoords.first][oneAheadCoords.second].symbol == ".") {
            targetSquare = startingSquare + pawnOffsetForward;
            struct Move currMove;
            currMove.start = startingSquare;
            currMove.end = targetSquare;
            moveList.push_back(currMove);
       }
       // if we are at starting position and the square two ahead is free
        if(board[twoAheadCoords.first][twoAheadCoords.second].symbol == "." and startingPiece.isAtStartingPosition) {
            targetSquare = startingSquare + pawnOffsetForward + pawnOffsetForward;
            struct Move currMove;
            currMove.start = startingSquare;
            currMove.end = targetSquare;
            moveList.push_back(currMove);
       }

       // if the square northwest is not free and has an enemy color
        if(board[northWestCoords.first][northWestCoords.second].symbol != "." and 
            startingPiece.color != board[northWestCoords.first][northWestCoords.second].color) {

            targetSquare = startingSquare + pawnOffetNorthWest;
            struct Move currMove;
            currMove.start = startingSquare;
            currMove.end = targetSquare;
            moveList.push_back(currMove);
        }

        // if the square northeast is not free and has an enemy color
        if(board[northEastCoords.first][northEastCoords.second].symbol != "." and 
            startingPiece.color != board[northEastCoords.first][northEastCoords.second].color) {
            targetSquare = startingSquare + pawnOffetNorthEast;
            struct Move currMove;
            currMove.start = startingSquare;
            currMove.end = targetSquare;
            moveList.push_back(currMove);
        }

       
       // if there is an enemy on the northeast and northwest diagonal, then we can move there
}


void ChessBoard::generateKnightMoves(Piece startingPiece, int startingSquare) {

    // Calculate all squares knight can jump to from current square
			
			//   if (IsPinned (startSquare)) {
			// 		continue;
	        // }
    pair <int, int> knightArrCoords;
    for (int i = 0; i < 8; i++) {
        int knightJumpSquare = startingSquare + allKnightJumpsArr[i];
        if (knightJumpSquare >= 0 && knightJumpSquare < 64) {
            knightArrCoords = chessCoordToArrayCoord[knightJumpSquare];
            if(startingPiece.color == board[knightArrCoords.first][knightArrCoords.second].color) {
                Move currMove;
                currMove.start = startingSquare;
                currMove.end = knightJumpSquare;
                moveList.push_back(currMove);
            }
            // int knightSquareY = knightJumpSquare / 8;
            // int knightSquareX = knightJumpSquare - knightSquareY * 8;
            // // Ensure knight has moved max of 2 squares on x/y axis (to reject indices that have wrapped around side of board)
            // int maxCoordMoveDst = System.Math.Max (System.Math.Abs (x - knightSquareX), System.Math.Abs (y - knightSquareY));
            // if (maxCoordMoveDst == 2) {
            // 	legalKnightJumps.Add ((byte) knightJumpSquare);
            // 	knightBitboard |= 1ul << knightJumpSquare;
            // }
        }
    }
}


void ChessBoard::displayMovesForPiece(int currSquare) {
    // go through moves list
    // if the move start starts with the current square index you are at,
    // look up the end index and reprint the board with green highlighting
    vector <pair<int, int>> coordsToMarkOnBoard;
    unordered_set<string> setOfMarkedCoords;
    pair<int, int> chessToArrIdx;
    for (size_t i = 0; i < moveList.size(); i++) {
        Move currMove = moveList[i];
        if (currMove.start == currSquare) {
            // get array coord of piece you need to change color and save to a list
            chessToArrIdx = chessCoordToArrayCoord[currMove.end];
            coordsToMarkOnBoard.push_back(chessToArrIdx);
        }
    }

    for (size_t i = 0; i < coordsToMarkOnBoard.size(); i++) {
        int currRow = coordsToMarkOnBoard[i].first;
        int currCol = coordsToMarkOnBoard[i].second;
        setOfMarkedCoords.insert(to_string(currRow) + to_string(currCol));
    }

    //coords to mark on board contains all moves that the piece can go to
    // ex: <0, 0> needs to be highlighted

    // re print board but with some pieces now highlighted
     int z = 8;
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << z << " ";
        for (int j = 0; j < 8; j++) {
            if(setOfMarkedCoords.count(to_string(i) + to_string(j))) {
                 cout << GREEN << board[i][j].symbol << RESET << "  ";
            }
            else {
                 cout << board[i][j].symbol << "  ";
            }
          
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










