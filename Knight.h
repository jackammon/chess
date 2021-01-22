// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"

/**
 * Implements a Knight object that extends Piece
 */
class Knight: public Piece {
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

#endif //_KNIGHT_H