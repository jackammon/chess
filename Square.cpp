// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "Square.h"
#include "Piece.h"


Square::Square(int file, int rank) :
_rank(rank), _file(file), _occupant(nullptr) {}


int Square::getRank() {
    return _rank;
}


int Square::getFile() {
    return _file;
}


bool Square::isOccupied() {
    bool returnValue = false;

    if (_occupant != nullptr) {
        returnValue = true;
    }
    return returnValue;
}


Piece* Square::getOccupant() {
    return _occupant;
}


void Square::setOccupant(Piece* occupant) {
    _occupant = occupant;
}


void Square::display() {
    if (_occupant != nullptr) {
        _occupant->display();
    }
    else {
        cout << "  ";
    }
}