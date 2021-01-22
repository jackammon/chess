// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _PLAYER_H
#define _PLAYER_H

#include "King.h"
#include <vector>

using namespace std;

// forward declarations
class Piece;
class King;

/**
 * Implements a Player object with a name, King piece, and set of Pieces
 */
class Player {

public:

    /**
     * Player Constructor
     *
     * @param name (string)
     * @param king (King)
     * @param pieces (set<Piece*>)
     */
    Player(string& name, King& king, set<Piece*>& pieces);

    /**
     * Gets the name attribute
     *
     * @return name (string)
     */
    string getName();

    /**
     * Returns a pointer to the players King object
     *
     * @return king (King*)
     */
    King* getKing();

    /**
     * Returns a set of pointers to the players pieces
     *
     * @return pieces (set<Piece*>)
     */
    set<Piece*>* getPieces();

    /**
     * Tries to make a move for the player.
     * Returns a boolean vector with three values
     * [0] is checkmate
     * [1] is draw
     * [2] is check
     *
     * @return boolean vector with check. draw, and checkmate states
     */
    vector<bool>* makeMove(vector<bool>& initiateDraw);

    /**
     * Captures the given piece
     *
     * @param piece (Piece&)
     */
    void capture(Piece& piece);


private:

    // private attributes
    string _name;
    King* _king;
    set<Piece*> _pieces;

};

#endif //_PLAYER_H