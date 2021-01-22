// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#ifndef _GAME_H
#define _GAME_H

using namespace std;

// forward declarations
class Piece;
class Player;
class Board;

/**
 * Implements a Game object that initializes and runs the main
 * logic of the game
 */
class Game {

public:

    /**
     * Initializes the game, creates the pieces/players/board
     * places each piece in the starting location
     */
    static void initialize();

    /**
     * Finalizes the game, deletes the singleton instance of Board
     */
    static void finalize();

    /**
     * Runs the game, turns, and will keep score
     */
    static void runGame();

    /**
     * Gets the next player based off of the current player
     *
     * @param current (Player&) - the current player
     * @return Player* to the next player
     */
    static Player* getNextPlayer(Player& current);

    /**
     * Gets the opponent player based off of the sent in player
     *
     * @param current (Player&) - the current player
     * @return Player* to the next player
     */
    static Player* getOpponentOf(Player& player);

private:

    static Player* player1;
    static Player* player2;

};

#endif //_GAME_H