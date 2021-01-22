// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "King.h"
#include "Square.h"


bool King::canMoveTo(Square& location) {

    bool validMove = false;
    Square* moveSquare = &location;

    // get if the square is occupied
    bool isOccupied = moveSquare->isOccupied();

    // get the destination squares file and rank
    int moveFile = moveSquare->getFile();
    int moveRank = moveSquare->getRank();

    // get the current locations file and rank
    int thisFile = getLocation()->getFile();
    int thisRank = getLocation()->getRank();

    if (!isOccupied || moveSquare->getOccupant()->getColor() != getColor())
    {
        if (moveRank == thisRank + 1 || moveRank == thisRank - 1) {
            if (thisFile == moveFile) {
                validMove = true;
            }
        }

        if (moveFile == thisFile + 1 || moveFile == thisFile - 1) {
            if (thisRank == moveRank ) {
                validMove = true;
            }
        }

        // up and to the left
        if (moveRank == thisRank + 1 && moveFile == thisFile - 1) {
            validMove = true;
        }

        // up and to the right
        if (moveRank == thisRank + 1 && moveFile == thisFile + 1) {
            validMove = true;
        }

        // down and to the left
        if (moveRank == thisRank - 1 && moveFile == thisFile - 1) {
            validMove = true;
        }

        // down and to the right
        if (moveRank == thisRank - 1 && moveFile == thisFile + 1) {
            validMove = true;
        }
    }

    return validMove;
}


void King::display() {
    cout << getColor() + "K" << flush;
}