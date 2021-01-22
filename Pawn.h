// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _PAWN_H
#define _PAWN_H

#include "Piece.h"

// forward declarations
class Square;
class Player;
class Queen;


/**
 * Implements a Pawn object that extends RestrictedPiece
 */
class Pawn: public Piece {
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
     * Moves the piece object to the given Square
     *
     * @param location (Square&)
     * @param byPlayer (Player&)
     * @return true if the move is valid else false
     */
    bool moveTo(Square& location, Player& byPlayer);

    /**
     * Flag function that maintains whether or not
     * a piece has moved. This is used to determine
     * valid moves.
     *
     * @return true if the piece has moved
     */
    bool hasMoved();

    /**
     * Displays the Bishop color and type
     */
    void display() override;

    /**
     * De-constructor for Pawn that deletes the instance of delegate
     */
    ~Pawn();

private:

    // private attributes
    bool moved = false;
    Queen* _delegate = nullptr;

};

#endif //_PAWN_H