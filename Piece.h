// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _PIECE_H
#define _PIECE_H

#include <string>

using namespace std;


// forward declarations
class Square;
class Player;

/**
 * Implements a Piece object with a location and color
 */
class Piece {

public:

    /**
     * Piece Constructor
     *
     * @param location - (Square*)
     * @param color - (string&)
     */
    Piece(Square* location, string& color);

    /**
     * Gets the color attribute
     * Returns "W" for white and "B" for black
     *
     * @return color (string)
     */
    string getColor();

    /**
     * Gets the Piece's board location
     * Returns a pointer to the square object the piece is on the
     * board, if it isn't on the board it will return null
     *
     * @return rank (int)
     */
    Square* getLocation();

    /**
     * Sets the location attribute to a pointer to a Square object
     *
     * @param location (Square*)
     */
    void setLocation(Square* location);

    /**
     * Checks if the piece object is on the board
     *
     * @return true if on the board else false
     */
    bool isOnSquare();

    /**
     * Checks if the piece object can move to the given Square
     *
     * @param location (Square&)
     * @return true if the move is valid else false
     */
    virtual bool canMoveTo(Square& location);

    /**
     * Moves the piece object to the given Square
     *
     * @param location (Square&)
     * @param byPlayer (Player&)
     * @return true if the move is valid else false
     */
    virtual bool moveTo(Square& location, Player& byPlayer);

    /**
      * Checks if the player's move put the opponent in check
      *
      * @param byPlayer (Player&)
      * @return true if the move opponent is in check
      */
    bool checkForCheck(Player& byPlayer);

    /**
     * Displays the piece color and type
     */
    virtual void display() = 0;

private:

    // private attributes
    Square* _location;
    string _color;

};

#endif //_PIECE_H