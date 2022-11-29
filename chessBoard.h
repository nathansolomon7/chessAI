#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Piece.h"
#include <unordered_map>
extern int WHITE_TURN;
extern int BLACK_TURN;
enum {
    ROOK = 0,
    KNIGHT,
    BISHOP,
    KING,
    QUEEN,
    PAWN,
    EMPTY
};
class ChessBoard {
    public:

        ChessBoard();
        ~ChessBoard();
        void initializeBoard();
        bool movePiece(std::string start, std::string end, int& currScore,  Piece (*localBoard)[8], bool isLocal);
        void printBoard();
        void generateMoves();
        void printAllMoves();
        int convertStringInputToChessCoord(std::string currPiece);
        void displayMovesForPiece(std::string currSquare);
        void clearMoveList();
        void generateRandomOpponentMove(std::string* movesArr);
        void generateBestMove(std::string* oponnentMove);
        int currColorTurn = 1;
        struct numSquaresInfo {
            int numNorth;
            int numSouth;
            int numEast;
            int numWest;
            int numNorthEast;
            int numNorthWest;
            int numSouthEast;
            int numSouthWest;
            int directionsArr[8];
        };

    private:
        Piece board[8][8];
        void findNumSquaresToEdge();
        void getPosition(std::string currCoord, int* positionArr);
        int getColCoord(char letter);
        int getRowCoord(char number);
        Piece initializePiece(std::string symbol, int value, int color, int pieceType, bool isSlidingPiece, bool isAtStartingPosition);
        bool isValidMove(int prevColor, int nextRow, int nextCol);
        bool isValidInput(std::string start, std::string end);

        
        void generateSlidingMoves(Piece startingPiece, int startingSquare);
        void generatePawnMoves(Piece startingPiece, int startingSquare);
        void generateKnightMoves(Piece startingPiece, int startingSquare);
        void generateKingMoves(Piece startingPiece, int startingSquare);
        void initChessCoordToArrayCoord();
        void initNumberCoordToLetterCoord();
        void printLocalBoard(Piece localBoard[8][8]);
        std::vector <std::pair<int, int>> moveSet;
        int allKnightJumpsArr[8] = { 15, 17, -17, -15, 10, -6, 6, -10 };
        int allKingJumpsArr[8] = {7, 8, 9, 1, -7, -8, -9, -1};
        int slidingPieceOffestsArr[8] = {8, -8, -1, 1, 7, -7, 9, -9 };
        struct Move {
            int start;
            int end;
        };
        int whiteScore = 0;
        int blackScore = 0;
        int runMinMaxOnBoard(int currDepth, int maxDepth, int currPointsScore, Move& bestMove, int optimalScore, Piece currBoard[8][8], int currColor);
        std::vector<Move> moveList;
        // std::unordered_map <string, int> arrayCoordToChessCoord;
        std::unordered_map <int, std::pair<int, int>> chessCoordToArrayCoord;
        // numSquaresInfo numSquaresToEdgeArr[8][8];
        std::unordered_map <int, numSquaresInfo> numSquaresToEdgeMap;
        std::unordered_map <int, std::string> numberCoordToLetterCoordMap;
};



#endif