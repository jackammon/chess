// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _BOARD_H
#define _BOARD_H

#include <ostream>
#include "Square.h"

// forward declarations
class Square;

/**
 * Implements a Board object that contains a matrix of
 * Square objects
 */
class Board {

public:

    /**
     * Returns a pointer to the board object
     * If a board doesn't it will call the constructor
     * creating a static instance of it
     *
     * @return square (Square*)
     */
    static Board* getInstance();

    /**
     * Deletes the singleton instance the board freeing allocated memory
     * used for Board when the game ends to prevent memory leaks
     */
    static void deleteInstance();

    /**
     * Returns a pointer to the Square object at
     * the given location in the board matrix
     *
     * @param rank (int)
     * @param file (int)
     * @return square (Square*)
     */
    Square* getSquareAt(int file, int rank);

    /**
     * Checks if the rank is clear from
     * the given Square& to the other given Square&
     *
     * @param from (Square&)
     * @param to (Square&)
     * @return true if not occupied else false
     */
    bool isClearRank(Square& from, Square& to);

    /**
     * Checks if the file is clear from
     * the given Square& to the other given Square&
     *
     * @param from (Square&)
     * @param to (Square&)
     * @return true if not occupied else false
     */
    bool isClearFile(Square& from, Square& to);

    /**
     * Checks if the diagonal is clear from
     * the given Square& to the other given Square&
     *
     * @param from (Square&)
     * @param to (Square&)
     * @return true if not occupied else false
     */
    bool isClearDiagonal(Square& from, Square& to);

    /**
     * Displays the the entire board
     */
    void display();

private:

    // private attributes
    static const int DIMENSION = 8;
    static Board* _instance;
    Square _squares[DIMENSION][DIMENSION];

    // zero-argument constructor
    Board();

};

#endif //_BOARD_H