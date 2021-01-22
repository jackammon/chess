// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _ROOK_H
#define _ROOK_H

#include "Piece.h"

/**
 * Implements a Rook object that extends RestrictedPiece
 */
class Rook: public Piece {
    using Piece::Piece; // lift constructor

public:

    /**
     * Checks if the piece object can move to the given Square
     *
     * @param location (Square&)
     * @return true if the move is valid else false
     */
    bool canMoveTo(Square& location) override;


    /**
     * Displays the Bishop color and type
     */
    void display() override;

};

#endif //_ROOK_H