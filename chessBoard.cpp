#include <iostream>
#include "chessBoard.h"
#include "Piece.h"
#include <unordered_map>
#include <utility>
#include <unordered_set>
using namespace std;
int WHITE_TURN = 0;
int BLACK_TURN = 1;
int GRAY_TURN = 2;
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
    board[7][0] = initializePiece(WHITE_ROOK, 5, WHITE_TURN, ROOK, true, true);
    board[7][1] = initializePiece(WHITE_KNIGHT, 3, WHITE_TURN, KNIGHT, false, true);
    board[7][2] = initializePiece(WHITE_BISHOP, 3, WHITE_TURN, BISHOP, true, true);
    board[7][3] = initializePiece(WHITE_QUEEN, 9, WHITE_TURN, QUEEN, true, true);
    board[7][4] = initializePiece(WHITE_KING, 90, WHITE_TURN, KING, false, true);
    board[7][5] = initializePiece(WHITE_BISHOP, 3, WHITE_TURN, BISHOP, true, true);
    board[7][6] = initializePiece(WHITE_KNIGHT, 3, WHITE_TURN, KNIGHT, false, true);
    board[7][7] = initializePiece(WHITE_ROOK, 5, WHITE_TURN, ROOK, true, true);
    // intialize white pawns
    board[6][0] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][1] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][2] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][3] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][4] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][5] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][6] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    board[6][7] = initializePiece(WHITE_PAWN, 1, WHITE_TURN, PAWN, false, true);
    // intialize black pawns
    board[1][0] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
    board[1][1] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
    board[1][2] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
    board[1][3] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
    board[1][4] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
    board[1][5] = initializePiece(BLACK_PAWN, -1, BLACK_TURN,PAWN, false, true);
    board[1][6] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
    board[1][7] = initializePiece(BLACK_PAWN, -1, BLACK_TURN, PAWN, false, true);
     // intialize black pieces
    board[0][0] = initializePiece(BLACK_ROOK, -5, BLACK_TURN, ROOK, true, true);
    board[0][1] = initializePiece(BLACK_KNIGHT, -3, BLACK_TURN, KNIGHT, false, true);
    board[0][2] = initializePiece(BLACK_BISHOP, -3, BLACK_TURN, BISHOP, true, true);
    board[0][3] = initializePiece(BLACK_QUEEN, -9, BLACK_TURN, QUEEN, true, true);
    board[0][4] = initializePiece(BLACK_KING, -90, BLACK_TURN, KING, false, true);
    board[0][5] = initializePiece(BLACK_BISHOP, -3, BLACK_TURN, BISHOP, true, true);
    board[0][6] = initializePiece(BLACK_KNIGHT, -3, BLACK_TURN, KNIGHT, false, true);
    board[0][7] = initializePiece(BLACK_ROOK, -5, BLACK_TURN, ROOK, true, true);


     for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = initializePiece(".", 0, GRAY_TURN, EMPTY, false, false);
        }
    }
    findNumSquaresToEdge();
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
            cout << "not a valid move 1" << endl;
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
   if(currPiece.type == PAWN and currPiece.isAtStartingPosition) {
    // cout << "turning isAtStartingPosition to false" << endl;
    currPiece.isAtStartingPosition = false;
   }
   board[currPosition[0]][currPosition[1]] = initializePiece(".", 0, GRAY_TURN, EMPTY, false, false);
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

bool ChessBoard::isValidMove(int currColor, int nextRow, int nextCol) {
    // cout << "the current piece's color: " << prevColor << endl;
    // cout << "the piece we are trying to move to color: " << endl;
    if (board[nextRow][nextCol].symbol != "." and board[nextRow][nextCol].color == currColor) {
        cout << "can not take a piece of your own color" << endl;
        return false;
    }
    if (currColor != currColorTurn or nextRow < 0 or nextRow > 7 or nextCol < 0 or nextCol > 7) {
        cout << "not a valid move 2" << endl;
        return false;
    }
    return true;
}

void ChessBoard::findNumSquaresToEdge() {
    int z = 0;
    numSquaresInfo squaresInfoArr[64];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            numSquaresInfo s = squaresInfoArr[z];
            s.numNorth = 7 - j;
            // cout <<  s.numNorth << endl;
            s.numSouth = j;
            s.numWest = i;
            s.numEast = 7 - i;
            s.numNorthWest = min(s.numNorth, s.numWest);
            s.numSouthEast = min(s.numSouth, s.numEast);
            s.numNorthEast = min(s.numNorth, s.numEast);
            s.numSouthWest = min(s.numSouth, s.numWest);
            s.directionsArr[0] = s.numNorth;
            s.directionsArr[1] = s.numSouth;
            s.directionsArr[2] = s.numWest;
            s.directionsArr[3] = s.numEast;
            s.directionsArr[4] = s.numNorthWest;
            s.directionsArr[5] = s.numSouthEast;
            s.directionsArr[6] = s.numNorthEast;
            s.directionsArr[7] = s.numSouthWest;
            numSquaresToEdgeMap[j * 8 + i] = s;
            z++;
        }
    }
    
}

void ChessBoard::generateMoves() {
    initChessCoordToArrayCoord();
    pair<int, int> currMove;
    // cout << "inside generatemoves" << endl;
   for (int i = 0; i < 64; i++) {
            currMove = chessCoordToArrayCoord[i];
            // cout << i << " -> " << currMove.first << ", " << currMove.second << endl;
            Piece p = board[currMove.first][currMove.second];
            
        if (p.color == currColorTurn and p.isSlidingPiece) {
            generateSlidingMoves(p, i);
        }
        if(p.color == currColorTurn and p.type == PAWN) {
            generatePawnMoves(p, i);
        }
        if(p.color == currColorTurn and p.type == KNIGHT) {
            generateKnightMoves(p, i);
        }
    }
}

void ChessBoard::printAllMoves(){
    // cout << "inside printAllMoves" << endl;
    pair<int, int> currMoveArrStart;
    pair<int, int> currMoveArrEnd;
    cout << "moveList size: " << moveList.size() << endl;
    for (size_t i = 0; i < moveList.size(); i++) {
        Move currMove = moveList[i];
        currMoveArrStart = chessCoordToArrayCoord[currMove.start];
        currMoveArrEnd = chessCoordToArrayCoord[currMove.end];
        cout << currMove.start << " -> " << currMove.end << endl;
        // cout << "[" << currMoveArrStart.first << ", " << currMoveArrStart.second << "] to ";
        //  cout << "[" << currMoveArrEnd.first << ", " << currMoveArrEnd.second << "]" << endl;
    }
}

void ChessBoard::initChessCoordToArrayCoord() {
    // cout << "inside initChessCoordToArrayCoord" << endl;
    int index = 0;
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j <= 7; j++) {
            chessCoordToArrayCoord[index] = make_pair(i, j);
            //   cout << index << " -> " << chessCoordpieceOnTargetSquare.colorToArrayCoord[index].first << " ,"<< chessCoordToArrayCoord[index].second << endl;
             index++;
        }
    }
    // cout << "end of initChessCoordToArrayCoord" << endl;
}

// void ChessBoard::initArrayCoordToChessCoord() {
//     arrayCoordToChessCoord[]
// }


void ChessBoard::generateSlidingMoves(Piece startingPiece, int startingSquare) {
        // for each direction
        // go through the squares in the current direction
        // cout << "inside generateSlidingMoves for " << startingSquare << " piece " << startingPiece.symbol << endl;
        pair<int, int> targetArrCoords;
        int startDirIdx = 0;
        int endDirIdx = 8;
        if (startingPiece.type == BISHOP) {
            startDirIdx = 4;
        }
        if (startingPiece.type == ROOK) {
            endDirIdx = 4;
        }
        for(int i = startDirIdx; i < endDirIdx; i++) { 
            // cout << "numSquaresToEdgeMap[startingSquare].directionsArr[" << i << "]: " << numSquaresToEdgeMap[startingSquare].directionsArr[i] << endl;
            for(int j = 0; j < numSquaresToEdgeMap[startingSquare].directionsArr[i]; j++) {
                int targetSquare = startingSquare + slidingPieceOffestsArr[i] * (j + 1);
                // cout << "generated target square " << targetSquare << endl;
                targetArrCoords = chessCoordToArrayCoord[targetSquare];
                Piece pieceOnTargetSquare = board[targetArrCoords.first][targetArrCoords.second];

                if(pieceOnTargetSquare.color == startingPiece.color) {
                    // cout << "pieceOnTargetSquare.color == startingPiece.color" << endl;
                    break;
                }
                struct Move currMove;
                currMove.start = startingSquare;
                currMove.end = targetSquare;
                // cout << "ADDING" << startingSquare << " ->  " << targetSquare << " TO MOVE list inside generateSlidingMoves" << endl;
                moveList.push_back(currMove);
                // cout << "pieceOnTargetSquare.color: " << pieceOnTargetSquare.color << endl;
                if (pieceOnTargetSquare.color != startingPiece.color and pieceOnTargetSquare.symbol != ".") {
                    // cout << "target square " << targetSquare << " has an enemy piece. break" << endl;
                    // enemy piece
                    break;
                }
            }
        }
}


void ChessBoard::generatePawnMoves(Piece startingPiece, int startingSquare) {
    // cout << "inside generatePawnMoves" << endl;
    pair<int, int> currCoord;
    currCoord = chessCoordToArrayCoord[startingSquare];
    // cout << "currPiece at: " << startingSquare << ": " << board[currCoord.first][currCoord.second].symbol << endl;
    pair<int, int> northWestCoords;
    pair<int, int> northEastCoords;
    pair <int, int> oneAheadCoords;
    pair <int, int> twoAheadCoords;
    int targetSquare;
    int pawnOffsetForward = 8;
    if (currColorTurn == 0) {
        pawnOffsetForward = 8;
    }
    else {
        pawnOffsetForward = -8;
    }
    int pawnOffetNorthWest = 7;
    int pawnOffetNorthEast = 9;
    // looking one ahead
    if(startingSquare + pawnOffsetForward <= 64) {
   
        oneAheadCoords = chessCoordToArrayCoord[startingSquare + pawnOffsetForward];
    }
    
    // looking two ahead
    if(startingSquare + pawnOffsetForward + pawnOffsetForward <= 64) {
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
    // cout << "oneAhead at " << startingSquare + pawnOffsetForward << ": " << board[oneAheadCoords.first][oneAheadCoords.second].symbol << endl;
    if(board[oneAheadCoords.first][oneAheadCoords.second].symbol == ".") {
        targetSquare = startingSquare + pawnOffsetForward;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        // cout << "adding " << startingSquare << " -> " << targetSquare << " to moves list" << endl;
        moveList.push_back(currMove);
    }
    // if we are at starting position and the square two ahead is free
    // cout << "twoAhead: " << board[twoAheadCoords.first][twoAheadCoords.second].symbol << endl;
    if(board[twoAheadCoords.first][twoAheadCoords.second].symbol == "." and startingPiece.isAtStartingPosition) {
        // cout << "startingPiece.isAtStartingPosition: " << startingPiece.isAtStartingPosition << endl;
        targetSquare = startingSquare + pawnOffsetForward + pawnOffsetForward;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        // cout << "adding the two pawn ahead move " << startingSquare << " -> " << targetSquare << " to moves list" << endl;
        moveList.push_back(currMove);
    }

    // if the square northwest is not free and has an enemy color
    if(board[northWestCoords.first][northWestCoords.second].symbol != "." and 
        startingPiece.color != board[northWestCoords.first][northWestCoords.second].color) {

        targetSquare = startingSquare + pawnOffetNorthWest;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        // cout << "adding " << startingSquare << " -> " << targetSquare << " to moves list" << endl;
        moveList.push_back(currMove);
    }

    // if the square northeast is not free and has an enemy color
    if(board[northEastCoords.first][northEastCoords.second].symbol != "." and 
        startingPiece.color != board[northEastCoords.first][northEastCoords.second].color) {
        targetSquare = startingSquare + pawnOffetNorthEast;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        // cout << "adding " << startingSquare << " -> " << targetSquare << " to moves list" << endl;
        moveList.push_back(currMove);
    }

    // cout << "end of generatePawnMoves" << endl;
    // if there is an enemy on the northeast and northwest diagonal, then we can move there
}


void ChessBoard::generateKnightMoves(Piece startingPiece, int startingSquare) {

    // Calculate all squares knight can jump to from current square
			
			//   if (IsPinned (startSquare)) {
			// 		continue;
	        // }
    int y = startingSquare / 8;
	int x = startingSquare - y * 8;
    pair <int, int> knightArrCoords;
    for (int i = 0; i < 8; i++) {
        int knightJumpSquare = startingSquare + allKnightJumpsArr[i];
        if (knightJumpSquare >= 0 && knightJumpSquare < 64) {
            knightArrCoords = chessCoordToArrayCoord[knightJumpSquare];
            if(startingPiece.color != board[knightArrCoords.first][knightArrCoords.second].color) {

                int knightSquareY = knightJumpSquare / 8;
                int knightSquareX = knightJumpSquare - knightSquareY * 8;
                // i have no idea why this fixes things
                // Ensure knight has moved max of 2 squares on x/y axis (to reject indices that have wrapped around side of board)
                int maxCoordMoveDst = max(abs(x - knightSquareX), abs(y - knightSquareY));
                if (maxCoordMoveDst == 2) {
                    Move currMove;
                    currMove.start = startingSquare;
                    currMove.end = knightJumpSquare;
                    // cout << "pushing a knight move" << endl;
                    moveList.push_back(currMove);
                }
                
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

int ChessBoard::convertStringInputToChessCoord(string currPiece) {
    char letterCol = currPiece[0];
    letterCol = tolower(letterCol);
    char numRowChar = currPiece[1];
    string numRowString =  string(1, numRowChar);
    return ((stoi(numRowString) - 1) * 8) + (letterCol - 'a');

}

void ChessBoard::displayMovesForPiece(string currPiece) {
    // go through moves list
    // if the move start starts with the current square index you are at,
    // look up the end index and reprint the board with green highlighting
    int currSquare = convertStringInputToChessCoord(currPiece);
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
    // cout << "number of moves for piece " << currPiece << ": " << coordsToMarkOnBoard.size() << endl;
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

void ChessBoard::clearMoveList() {
    moveList.clear();
}










