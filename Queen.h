// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"

/**
 * Implements a Queen object that extends Piece
 */
class Queen: public Piece {
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

#endif //_QUEEN_H