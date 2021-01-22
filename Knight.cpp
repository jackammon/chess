// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "Knight.h"
#include "Board.h"


bool Knight::canMoveTo(Square& location) {

    bool validMove = false;
    Square* moveSquare = &location;
    Board* board = Board::getInstance();

    // get if the square is occupied
    bool isOccupied = moveSquare->isOccupied();

    // get the destination squares file and rank
    int moveFile = moveSquare->getFile();
    int moveRank = moveSquare->getRank();

    // get the current locations file and rank
    int thisFile = getLocation()->getFile();
    int thisRank = getLocation()->getRank();

    if (!isOccupied || moveSquare->getOccupant()->getColor() != getColor()) {

        if (abs(thisRank - moveRank) == 2 && abs(thisFile - moveFile) == 1) {
            validMove = true;
        }

        if (abs(thisFile - moveFile) == 2 && abs(thisRank - moveRank) == 1) {
            validMove = true;
        }
    }

    return validMove;
}


void Knight::display() {
    cout << getColor() + "N" << flush;
}