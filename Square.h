// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _SQUARE_H
#define _SQUARE_H

#include "Piece.h"

// forward declarations
class Piece;

/**
 * Implements a Square object with a rank and file (row and column)
 */
class Square {

public:
    
    /**
     * Square Constructor
     *
     * @param rank - row
     * @param file - column
     */
    explicit Square(int file = 0, int rank = 0);

    /**
     * Gets rank attribute
     *
     * @return rank (int)
     */
    int getRank();

    /**
     * Gets File attribute
     *
     * @return file (int)
     */
    int getFile();

    /**
     * Checks if the square object contains
     * any piece objects
     *
     * @return true if occupied else false
     */
    bool isOccupied();

    /**
     * Returns a pointer to the Piece object
     * If there is not occupant the pointer will be null
     *
     * @return occupant (Piece*)
     */
    Piece* getOccupant();

    /**
     * Sets the occupant attribute to a pointer to a Piece object
     *
     * @param occupant (Piece*)
     */
    void setOccupant(Piece* occupant);

    /**
     * Displays the occupants of a square
     * If there is not occupant two whitespaces
     * will output
     */
    void display();

private:

    // private attributes
    int _rank;
    int _file;
    Piece* _occupant;

};

#endif //_SQUARE_H