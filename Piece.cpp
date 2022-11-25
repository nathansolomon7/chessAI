#include <iostream>
#include "Piece.h"
#include <string>
using namespace std;

Piece Piece::initializePiece(string symbol, int value, int color) {
    Piece newPiece;
    newPiece.symbol = symbol;
    newPiece.value = value;
    newPiece.color = color;
    return newPiece;
}