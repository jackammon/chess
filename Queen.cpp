// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "Queen.h"
#include "Board.h"


bool Queen::canMoveTo(Square& location) {

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

        // if vertical move
        if (moveFile == thisFile) {

            // if the move is one square away
            if (abs(moveRank - thisRank) == 1) {

                if (board->getSquareAt(moveFile, moveRank)->getOccupant()
                == nullptr) {
                    validMove = true;
                }
                else if (board->getSquareAt(moveFile,
                        moveRank)->getOccupant()->getColor()
                        != this->getColor()) {
                    validMove = true;
                }
            }
            else {
                // if up move
                if (moveRank > thisRank) {

                    // if the move is clear file
                    if (board->isClearFile(*board->getSquareAt(thisFile,
                            thisRank + 1), *board->getSquareAt(moveFile,
                                    moveRank - 1))) {
                        validMove = true;
                    }
                }
                else {
                    // if the move is clear file
                    if (board->isClearFile(*board->getSquareAt(thisFile,
                            thisRank - 1), *board->getSquareAt(moveFile,
                                    moveRank + 1))) {
                        validMove = true;
                    }
                }
            }
        } // if horizontal move
        else if (moveRank == thisRank) {

            // if the move is one square away
            if (abs(moveFile - thisFile) == 1) {
                if (board->getSquareAt(moveFile, moveRank)->getOccupant()
                    == nullptr) {
                    validMove = true;
                }
                else if (board->getSquareAt(moveFile,
                                            moveRank)->getOccupant()->getColor()
                         != this->getColor()) {
                    validMove = true;
                }
            }
            else {
                // if right move
                if (moveFile > thisFile) {

                    // if the move is clear rank
                    if (board->isClearRank(*board->getSquareAt(thisFile + 1,
                            thisRank), *board->getSquareAt(moveFile - 1,
                                    moveRank))) {
                        validMove = true;
                    }
                }
                else if (moveFile < thisFile) {

                    // if the move is clear rank
                    if (board->isClearRank(*board->getSquareAt(thisFile - 1,
                            thisRank), *board->getSquareAt(moveFile + 1,
                                    moveRank))) {
                        validMove = true;
                    }
                }
                else {
                    // if the single square is clear
                    if (board->isClearFile(*board->getSquareAt(thisFile,
                            thisRank - 1), *board->getSquareAt(moveFile,
                                    moveRank + 1))) {
                        validMove = true;
                    }
                }
            }
        }
        // if the move in one square away
        else if (abs(thisFile - moveFile) == 1 &&
            abs(thisRank - moveRank) == 1) {
            if (board->getSquareAt(moveFile, moveRank)->getOccupant()
                == nullptr) {
                validMove = true;
            }
            else if (board->getSquareAt(moveFile,
                                        moveRank)->getOccupant()->getColor()
                     != this->getColor()) {
                validMove = true;
            }
        }
        else {
            // up and to the left
            if (moveFile < thisFile && moveRank > thisRank) {
                if (board->isClearDiagonal(*board->getSquareAt(thisFile - 1,
                        thisRank + 1), *board->getSquareAt(moveFile + 1,
                                moveRank - 1))) {
                    validMove = true;
                }
            }

            // down and to the left
            if (moveFile < thisFile && moveRank < thisRank) {
                if (board->isClearDiagonal(*board->getSquareAt(thisFile - 1,
                        thisRank - 1), *board->getSquareAt(moveFile + 1,
                                moveRank + 1))) {
                    validMove = true;
                }
            }

            // up and to the right
            if (moveFile > thisFile && moveRank > thisRank) {
                if (board->isClearDiagonal(*board->getSquareAt(thisFile + 1,
                        thisRank + 1), *board->getSquareAt(moveFile - 1,
                                moveRank - 1))) {
                    validMove = true;
                }
            }

            // down and to the right
            if (moveFile > thisFile && moveRank < thisRank) {
                if (board->isClearDiagonal(*board->getSquareAt(thisFile + 1,
                        thisRank - 1), *board->getSquareAt(moveFile - 1,
                                moveRank + 1))) {
                    validMove = true;
                }
            }
        }
    }

    return validMove;
}


void Queen::display() {
    cout << getColor() + "Q" << flush;
}