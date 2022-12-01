#include <iostream>
#include "chessBoard.h"
#include "Piece.h"
#include <random>
#include <unordered_map>
#include <utility>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;
int WHITE_TURN = 0;
int BLACK_TURN = 1;
int GRAY_TURN = 2;
string BLACK_KING   = "\u265A";
string BLACK_QUEEN	= "\u265B";
string BLACK_ROOK   = "\u265C";	
string BLACK_BISHOP = "\u265D";
string BLACK_KNIGHT = "\u265E";
string BLACK_PAWN	= "\u265F";	
// TODO: implement king moves and check and checkmate
// implement minmax algorithm

string WHITE_KING	= "\u2654";
string WHITE_QUEEN	= "\u2655";
string WHITE_ROOK	= "\u2656";	
string WHITE_BISHOP	= "\u2657";	
string WHITE_KNIGHT	= "\u2658";
string WHITE_PAWN	= "\u2659";

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
    initNumberCoordToLetterCoord();
}

int ChessBoard::getColCoord(char letter) {
    letter = tolower(letter);
    // cout << "col coordinate: " << letter - 97 << endl;
    return letter - 97;
}

int ChessBoard::getRowCoord(char number) {
    // input to board mapping
    int num = (int)(number - 48);
    return rowNumtoBoard[num];
}


void ChessBoard::getPosition(string currCoord, int* positionArr) {
    
    positionArr[0] = getRowCoord(currCoord[1]);
    positionArr[1] = getColCoord(currCoord[0]);
}

bool ChessBoard::movePiece(string start, string end, Piece (*localBoard)[8], int currColorTurnLocal, Piece &takenPiece) {
    if (!isValidInput(start, end) ) {
            cout << "not a valid move 1" << endl;
            return false;
    }

        int currPosition[2];
        int nextPosition[2];
        getPosition(start, currPosition);
        getPosition(end, nextPosition);
        // piece we are trying to move
        Piece currPiece = localBoard[currPosition[0]][currPosition[1]];
        // cout << "piece we are trying to move: " << currPiece.symbol << endl;
        if(!isValidMove(currPiece.color, nextPosition[0], nextPosition[1], currColorTurnLocal, localBoard)) {
                cout << "input from " << start << " -> " << end << " is not valid (see below)" << endl;
                cout << currPiece.symbol << " -> " << localBoard[nextPosition[0]][nextPosition[1]].symbol << endl;
                return false;
        }
        // replace piece with empty space, as you have just moved it
        if(currPiece.type == PAWN and currPiece.isAtStartingPosition) {

            currPiece.isAtStartingPosition = false;
        }
        (localBoard)[currPosition[0]][currPosition[1]] = initializePiece(".", 0, GRAY_TURN, EMPTY, false, false);
        takenPiece = (localBoard)[nextPosition[0]][nextPosition[1]];
        (localBoard)[nextPosition[0]][nextPosition[1]] = currPiece;
        return true;
   
}

int ChessBoard::evaluateScore(Piece (*localBoard)[8]) {
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
           if(localBoard[i][j].symbol != ".") {
                score += localBoard[i][j].value;
           }
        }
    }
    return score;
}


bool ChessBoard::isValidInput(string start, string end) {
    start[0] = tolower(start[0]);
    start[1] = tolower(start[1]);
    end[0] = tolower(end[0]);
    end[1] = tolower(end[1]);
     if (start[0] > 'h' or start[0] < 'a' 
    or start[1] > '8' or start[1] < '1'  or
    end[0] > 'h' or end[0] < 'a' 
    or end[1] > '8' or end[1] < '1'  ) {
            cout << start << " -> " << end << " is not a valid input " << endl;
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

void ChessBoard::printLocalBoard(Piece localBoard[8][8]) {
    int z = 8;
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << z << " ";
        for (int j = 0; j < 8; j++) {
           cout << localBoard[i][j].symbol << "  ";
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

bool ChessBoard::isValidMove(int currColor, int nextRow, int nextCol, int currColorTurnLocal, Piece (*localBoard)[8]) {

    if (localBoard[nextRow][nextCol].symbol != "." and localBoard[nextRow][nextCol].color == currColor) {
        cout << "can not take a piece of your own color" << endl;
        cout << "piece trying to be taken: " << localBoard[nextRow][nextCol].symbol << endl;
        return false;
    }

    if (currColor != currColorTurnLocal or nextRow < 0 or nextRow > 7 or nextCol < 0 or nextCol > 7) {
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

void ChessBoard::generateMoves( Piece (*currBoard)[8], int currColorTurnLocal, vector<Move>& currMoveList) {
    initChessCoordToArrayCoord();
    pair<int, int> currMove;

   for (int i = 0; i < 64; i++) {
            currMove = chessCoordToArrayCoord[i];
            Piece p = currBoard[currMove.first][currMove.second];

        if (p.color == currColorTurnLocal and p.type == PAWN) {
            generatePawnMoves(p, i, currBoard, currColorTurnLocal, currMoveList);
        }
        if (p.color == currColorTurnLocal and p.isSlidingPiece) {
            generateSlidingMoves(p, i, currBoard, currMoveList);
        }
        if (p.color == currColorTurnLocal and p.type == KNIGHT) {
            generateKnightMoves(p, i, currBoard, currMoveList);
        }
        if (p.color == currColorTurnLocal and p.type == KING) {
            generateKingMoves(p, i, currBoard, currMoveList);
        }
    }
}

void ChessBoard::printAllMoves(){
    cout << "moveList size: " << moveList.size() << endl;
    for (size_t i = 0; i < moveList.size(); i++) {
        Move currMove = moveList[i];
        string currMoveStartString = numberCoordToLetterCoordMap[currMove.start];
        string currMoveEndString = numberCoordToLetterCoordMap[currMove.end];
        cout << currMoveStartString << " -> " << currMoveEndString << endl;
    }
}

void ChessBoard::initChessCoordToArrayCoord() {
    // cout << "inside initChessCoordToArrayCoord" << endl;
    int index = 0;
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j <= 7; j++) {
            chessCoordToArrayCoord[index] = make_pair(i, j);
             index++;
        }
    }
}


void ChessBoard::generateSlidingMoves(Piece startingPiece, int startingSquare,  Piece (*currBoard)[8], vector<Move> &currMoveList) {
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
        for(int i = startDirIdx; i < endDirIdx; i++) { 
            for(int j = 0; j < numSquaresToEdgeMap[startingSquare].directionsArr[i]; j++) {
                int targetSquare = startingSquare + slidingPieceOffestsArr[i] * (j + 1);
                
                targetArrCoords = chessCoordToArrayCoord[targetSquare];
                Piece pieceOnTargetSquare = currBoard[targetArrCoords.first][targetArrCoords.second];

                if(pieceOnTargetSquare.color == startingPiece.color) {
                    
                    break;
                }
                struct Move currMove;
                currMove.start = startingSquare;
                currMove.end = targetSquare;
                currMoveList.push_back(currMove);
                if (pieceOnTargetSquare.color != startingPiece.color and pieceOnTargetSquare.symbol != ".") {
                    // enemy piece
                    break;
                }
            }
        }
}

// TODO: fix bug on pawn's possible moves wrapping around board
void ChessBoard::generatePawnMoves(Piece startingPiece, int startingSquare,  Piece (*currBoard)[8], int currColorLocal, vector<Move> &currMoveList) {
    pair<int, int> currCoord;
    currCoord = chessCoordToArrayCoord[startingSquare];
    pair<int, int> northWestCoords;
    pair<int, int> northEastCoords;
    pair <int, int> oneAheadCoords;
    pair <int, int> twoAheadCoords;
    int targetSquare;
    int pawnOffsetForward = 8;
    int pawnOffetNorthWest = 7;
    int pawnOffetNorthEast = 9;
    if (currColorLocal == WHITE_TURN) {
        pawnOffsetForward = 8;
    }
    else {
        pawnOffsetForward = -8;
        pawnOffetNorthEast = -9;
        pawnOffetNorthWest = -7;
    }

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
    if(currBoard[oneAheadCoords.first][oneAheadCoords.second].symbol == ".") {
        targetSquare = startingSquare + pawnOffsetForward;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        currMoveList.push_back(currMove);
    }
    // if we are at starting position and the square two ahead is free
    if(currBoard[twoAheadCoords.first][twoAheadCoords.second].symbol == "." and startingPiece.isAtStartingPosition) {
        targetSquare = startingSquare + pawnOffsetForward + pawnOffsetForward;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        currMoveList.push_back(currMove);
    }

    // if the square northwest is not free and has an enemy color
    if(currBoard[northWestCoords.first][northWestCoords.second].symbol != "." and 
        startingPiece.color != currBoard[northWestCoords.first][northWestCoords.second].color) {

        targetSquare = startingSquare + pawnOffetNorthWest;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        currMoveList.push_back(currMove);
    }

    // if the square northeast is not free and has an enemy color
    if(currBoard[northEastCoords.first][northEastCoords.second].symbol != "." and 
        startingPiece.color != currBoard[northEastCoords.first][northEastCoords.second].color) {
        targetSquare = startingSquare + pawnOffetNorthEast;
        struct Move currMove;
        currMove.start = startingSquare;
        currMove.end = targetSquare;
        currMoveList.push_back(currMove);
    }


    // if there is an enemy on the northeast and northwest diagonal, then we can move there
}


void ChessBoard::generateKnightMoves(Piece startingPiece, int startingSquare,  Piece (*currBoard)[8], vector<Move> &currMoveList) {

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
            if(startingPiece.color != currBoard[knightArrCoords.first][knightArrCoords.second].color) {

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
                    currMoveList.push_back(currMove);
                }
                
            }
        }
    }
}

void ChessBoard::generateKingMoves(Piece startingPiece, int startingSquare,  Piece (*currBoard)[8], vector<Move> &currMoveList) {
    // TODO: implement check
     pair <int, int> kingArrCoords;
     for (int i = 0; i < 8; i++) {
        int kingJumpSquare = startingSquare + allKingJumpsArr[i];
         if (kingJumpSquare >= 0 && kingJumpSquare < 64) {
            kingArrCoords = chessCoordToArrayCoord[kingJumpSquare];
            if(startingPiece.color != currBoard[kingArrCoords.first][kingArrCoords.second].color) {
                Move currMove;
                currMove.start = startingSquare;
                currMove.end = kingJumpSquare;
                currMoveList.push_back(currMove);
            }  
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

void ChessBoard::generateRandomOpponentMove(string* movesArr) {
    int numMoves = (int)moveList.size();
    random_device rd;     // Only used once to initialise (seed) engine
    mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(0,numMoves); // Guaranteed unbiased

    auto randomIdx = uni(rng);
    Move randomMove = moveList[randomIdx];
    // convert chess cooridantes to letter coordinates
    int startSquare = randomMove.start;
    int targetSquare = randomMove.end; 
    string startCoord;
    string targetCoord;
    startCoord = numberCoordToLetterCoordMap[startSquare];
    targetCoord = numberCoordToLetterCoordMap[targetSquare];
    cout << startCoord << " -> " << targetCoord << endl;
    movesArr[0] = startCoord;
    movesArr[1] = targetCoord;
}

void ChessBoard::initNumberCoordToLetterCoord() {
    int z = 0;
    for (int i = 0; i < 8; i++) {
        for (char j = 'a'; j <= 'h'; j++) {
            // convert to char
            int rowNum = i + 1;
             numberCoordToLetterCoordMap[z] = (string(1, j) +  to_string(rowNum));
             z++;
        }
    }
}
int globalCounter = 0;
// TODO: fix bug that allows user to move pieces illegally 
void ChessBoard::generateBestMove(string* oponnentMove) {
    
    Move bestMove;
    bestMove.start = 0;
    bestMove.end = 0;
    Piece localBoard[8][8];
    memcpy(localBoard, board, 64 * sizeof(Piece));
    printLocalBoard(localBoard);
    auto start = chrono::high_resolution_clock::now();
    cout << "AI is loading...." << endl;
    runMinMaxOnBoard(0, 7, bestMove, localBoard, currColorTurnGlobal, INT_MIN, INT_MAX);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << duration.count() << " seconds" << endl;
    string startCoord = numberCoordToLetterCoordMap[bestMove.start];
    string endCoord = numberCoordToLetterCoordMap[bestMove.end];
    cout << "AI is finished" << endl;
    cout << "num nodes visited (representing num moves given starting board): " << globalCounter << endl;
    oponnentMove[0] = startCoord;
    oponnentMove[1] = endCoord;
    // convert best move start and end to letter coords 
    // pass the letter coords into movePiece function
}
// white will be maximizing, black will be minimizing
int ChessBoard::runMinMaxOnBoard(int currDepth, int maxDepth, Move& bestMove, Piece currBoard[8][8], int currColor, int alpha, int beta) {
  
    globalCounter++;
    if (currDepth == maxDepth) {

            int terminalScore = evaluateScore(currBoard);
            return terminalScore;
    }

    string startCoord;
    string endCoord;
    vector<Move> currMoveList;

    generateMoves(currBoard, currColor, currMoveList);
    if (currMoveList.size() == 0) {
        cout << "ran out of moves to generate" << endl;
        return 0;
    }

    int numPossibleMoves = currMoveList.size();

    Piece takenPiece;
    if (currColor == WHITE_TURN) {
        int maxValue = INT_MIN;
        for (int i = 0; i < numPossibleMoves; i++) {
            // make the move
            Move currMove = currMoveList[i];
            startCoord = numberCoordToLetterCoordMap[currMove.start];
            endCoord = numberCoordToLetterCoordMap[currMove.end];
            movePiece(startCoord, endCoord, currBoard, currColor, takenPiece);
            int returnedResult = runMinMaxOnBoard(currDepth + 1, maxDepth, bestMove, currBoard, BLACK_TURN, alpha, beta);
            undoMove(endCoord, startCoord, currBoard, takenPiece);
            if (returnedResult > maxValue) {
                 if (currDepth == 0) {
                    bestMove = currMove;
                }
                 maxValue = returnedResult;
            }

            if (returnedResult >= beta) {
                return maxValue;
            }

            alpha = max(returnedResult, alpha);
            // cout << "new max value of " << currScore << " for white has been found. We are at depth " << currDepth << endl;
        }
        return maxValue; 
    }
    // make sure that it does not make moves for the gray empty pice
    else {
        int minValue = INT_MAX;
         for (int i = 0; i < numPossibleMoves; i++) {
            // make the move
            Move currMove = currMoveList[i];
            startCoord = numberCoordToLetterCoordMap[currMove.start];
            endCoord = numberCoordToLetterCoordMap[currMove.end];
   
            movePiece(startCoord, endCoord, currBoard, currColor, takenPiece);
            // clearMoveList();
            int returnedResult = runMinMaxOnBoard(currDepth + 1, maxDepth, bestMove, currBoard, WHITE_TURN, alpha, beta);
            undoMove(endCoord, startCoord, currBoard, takenPiece);

            if (returnedResult < minValue) {
                if (currDepth == 0) {
                    bestMove = currMove;
                }
                minValue = returnedResult;
            }
             if (returnedResult <= alpha) {
                return minValue;
            }
            beta = min(beta, returnedResult);
        }

        return minValue; 
    }
}

void ChessBoard::undoMove(string endCoord, string initialCoord, Piece (*localBoard)[8], Piece takenPieceToPutBack) {
    int endPosition[2];
    int initialPosition[2];
    getPosition(endCoord, endPosition);
    getPosition(initialCoord, initialPosition);

    // get the piece that was moved previously 
    Piece endPositionPiece = localBoard[endPosition[0]][endPosition[1]];
    // replace the end position with the piece that was there before moving our piece previously
    localBoard[endPosition[0]][endPosition[1]] = takenPieceToPutBack;
    // put our moved piece back to its initial position
    localBoard[initialPosition[0]][initialPosition[1]] = endPositionPiece;
}






