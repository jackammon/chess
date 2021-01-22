// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "Pawn.h"
#include "Square.h"
#include "Queen.h"


bool Pawn::canMoveTo(Square& location) {

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

    if (_delegate != nullptr) {
        validMove = _delegate->canMoveTo(location);
    }
    else if (getColor() == "W") {
        if (hasMoved()) {
            if (thisRank + 1 == moveRank && thisFile == moveFile
            && !isOccupied) {
                validMove = true;
            }

            if (thisRank + 1 == moveRank && thisFile == moveFile - 1
            && isOccupied) {
                validMove = true;
            }

            if (thisRank + 1 == moveRank && thisFile == moveFile + 1
            && isOccupied) {
                validMove = true;
            }
        }
        else {
            if (thisRank + 1 == moveRank || thisRank + 2 == moveRank) {
                if (thisFile == moveFile && !isOccupied) {
                    validMove = true;
                    moved = true;
                }
            }
        }
    }
    else {
        if (hasMoved()) {
            if (thisRank - 1 == moveRank && thisFile == moveFile
            && !isOccupied) {
                validMove = true;
            }

            if (thisRank - 1 == moveRank && thisFile == moveFile - 1
            && isOccupied) {
                validMove = true;
            }

            if (thisRank - 1 == moveRank && thisFile == moveFile + 1
            && !isOccupied) {
                validMove = true;
            }
        }
        else {
            if (thisRank - 1 == moveRank || thisRank - 2 == moveRank) {
                if (thisFile == moveFile && !isOccupied) {
                    validMove = true;
                    moved = true;
                }
            }
        }
    }

    return validMove;
}


bool Pawn::moveTo(Square& location, Player& byPlayer) {

    bool isCheck;

    // call the super of piece to move the piece
    Piece::moveTo(location, byPlayer);

    // get the two squares involved in the move
    Square* moveSquare = &location;

    if (moveSquare->getRank() == 7 && getColor() == "W") {

        string color = getColor();
        _delegate =  new Queen(&location, color);
    }
    else if (moveSquare->getRank() == 0 && getColor() == "B") {

        string color = getColor();
        _delegate =  new Queen(&location, color);
    }

    // check for check
    if (_delegate != nullptr) {
        isCheck = _delegate->checkForCheck(byPlayer);
    }
    else {
        isCheck = checkForCheck(byPlayer);
    }

    // return true upon successful move
    return isCheck;
}


bool Pawn::hasMoved() {
    return moved;
}


void Pawn::display() {
    cout << getColor() + "P" << flush;
}

Pawn::~Pawn() {
    delete _delegate;
}