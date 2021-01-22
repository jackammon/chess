// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "Board.h"
#include "Square.h"

using namespace std;

Board* Board::_instance;


Board::Board() {
    // for each column
    for (int i = 0; i < DIMENSION; i++) {

        // for each row
        for (int j = 0; j < DIMENSION; j++) {

            // create a new Square
            _squares[i][j] = Square(i, j);
        }
    }
}


Board* Board::getInstance() {

    if (_instance == nullptr) {
        _instance = new Board();
    }
    return _instance;
}


void Board::deleteInstance() {
    delete _instance;
}


Square* Board::getSquareAt(int file, int rank) {
    return &_squares[file][rank];
}


bool Board::isClearRank(Square& from, Square& to) {

    bool isClear = true;

    Square* toSquare = &to;
    Square* fromSquare = &from;

    // get the destination squares file and rank
    int toFile = toSquare->getFile();
    int toRank = toSquare->getRank();

    // get the current locations file and rank
    int fromFile = fromSquare->getFile();
    int fromRank = fromSquare->getRank();

    // if files are the same
    if (toRank == fromRank) {

        // move left
        if (fromFile > toFile) {

            // for each rank between the given squares including the ends
            for (int i = toFile; i <= fromFile; i++) {

                // if the square is occupied then the rank is not clear
                if (_instance->getSquareAt(i, toRank)->isOccupied()) {
                    isClear = false;
                }
            }
        }
        else if (fromFile < toFile) {

            // for each rank between the given squares including the ends
            for (int i = fromFile; i <= toFile; i++) {

                // if the square is occupied then the rank is not clear
                if (_instance->getSquareAt(i, toRank)->isOccupied()) {
                    isClear = false;
                }
            }
        }
    }

    return isClear;
}


bool Board::isClearFile(Square& from, Square& to) {

    bool isClear = true;

    Square* toSquare = &to;
    Square* fromSquare = &from;

    // get the destination squares file and rank
    int toFile = toSquare->getFile();
    int toRank = toSquare->getRank();

    // get the current locations file and rank
    int fromFile = fromSquare->getFile();
    int fromRank = fromSquare->getRank();

    // if files are the same
    if (toFile == fromFile) {

        if (fromRank > toRank) {

            // for each rank between the given squares including the ends
            for (int i = toRank; i <= fromRank; i++) {

                // if the square is occupied then the rank is not clear
                if (_instance->getSquareAt(toFile, i)->isOccupied()) {
                    isClear = false;
                }
            }
        }
        else if (fromRank < toRank) {

            // for each rank between the given squares including the ends
            for (int i = fromRank; i <= toRank; i++) {

                // if the square is occupied then the rank is not clear
                if (_instance->getSquareAt(toFile, i)->isOccupied()) {
                    isClear = false;
                }
            }
        }
        else {
               if (toSquare->isOccupied() &&
               toSquare->getOccupant()->getColor() ==
               fromSquare->getOccupant()->getColor()) {
                   isClear = false;
               }
        }
    }

    return isClear;
}


bool Board::isClearDiagonal(Square& from, Square& to) {

    bool isClear = true;

    Square* toSquare = &to;
    Square* fromSquare = &from;

    // get the destination squares file and rank
    int toFile = toSquare->getFile();
    int toRank = toSquare->getRank();

    // get the current locations file and rank
    int fromFile = fromSquare->getFile();
    int fromRank = fromSquare->getRank();

    // if the slope is 1
    if (toFile == fromFile && toRank == fromRank)
    {
        if (_instance->getSquareAt(toFile, toRank)->isOccupied())
        {
            isClear = false;
        }
    }
    else if (toFile - fromFile != 0) {

        if (abs(toRank - fromRank) / abs(toFile - fromFile) == 1) {
            // up and to the left
            if (toFile < fromFile && toRank > fromRank) {
                int j = fromRank;

                // for each square
                for (int i = fromFile; i >= toFile; i--) {

                    // if the square is occupied then the diagonal is not clear
                    if (_instance->getSquareAt(i, j)->isOccupied()) {
                        isClear = false;
                    }
                    j++;
                }
            }

            // down and to the left
            if (toFile < fromFile && toRank < fromRank) {
                int j = fromRank;

                // for each square
                for (int i = fromFile; i >= toFile; i--) {

                    // if the square is occupied then the diagonal is not clear
                    if (_instance->getSquareAt(i, j)->isOccupied()) {
                        isClear = false;
                    }
                    j--;
                }
            }

            //  up and to the right
            if (toFile > fromFile && toRank > fromRank) {
                int j = fromRank;

                // for each square
                for (int i = fromFile; i <= toFile; i++) {

                    // if the square is occupied then the diagonal is not clear
                    if (_instance->getSquareAt(i, j)->isOccupied()) {
                        isClear = false;
                    }
                    j++;
                }
            }

            // down and to the right
            if (toFile > fromFile && toRank < fromRank) {
                int j = fromRank;

                // for each square
                for (int i = fromFile; i <= toFile; i++) {

                    // if the square is occupied then the diagonal is not clear
                    if (_instance->getSquareAt(i, j)->isOccupied()) {
                        isClear = false;
                    }
                    j--;
                }
            }
        }
        else {
            isClear = false;
        }
    }
    else {
        isClear = false;
    }

    return isClear;
}


void Board::display() {

    string hDivider = "  +----+----+----+----+----+----+----+----+ \n";
    string letters = "     a    b    c    d    e    f    g    h\n";

    cout << letters << flush;
    int rowNumber = 8;

    // for each row
    for (int i = 7; i >= 0; i--) {
        cout << hDivider << flush;

        // start newline and print row number
        cout << rowNumber << flush;

        // for each square
        for (int j = 0; j < 8; j++) {
            cout << " | " << flush;

            // print square
            getSquareAt(j, i)->display();
        }
        
        // print last border and row number
        cout << " | " << flush;
        cout << rowNumber << "\n" << flush;
        
        rowNumber--;
    }
    
    // print last horizontal divider and letters
    cout << hDivider << flush;
    cout << letters << flush;
}