// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <set>
#include <iostream>
#include <vector>
#include "Game.h"
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Square.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Player.h"

using namespace std;

Player* Game::player1 = nullptr;
Player* Game::player2 = nullptr;


void Game::initialize() {

    // declare constants
    string BLACK = "B";
    string WHITE = "W";

    // create the board
    Board* board = Board::getInstance();

    // get pointers to the board squares a row at a time

    // row 2 (Black pawns)
    Square* square0_6 = board->getSquareAt(0, 6);
    Square* square1_6 = board->getSquareAt(1, 6);
    Square* square2_6 = board->getSquareAt(2, 6);
    Square* square3_6 = board->getSquareAt(3, 6);
    Square* square4_6 = board->getSquareAt(4, 6);
    Square* square5_6 = board->getSquareAt(5, 6);
    Square* square6_6 = board->getSquareAt(6, 6);
    Square* square7_6 = board->getSquareAt(7, 6);

    // row 7 (White Pawns)
    Square* square0_1 = board->getSquareAt(0, 1);
    Square* square1_1 = board->getSquareAt(1, 1);
    Square* square2_1 = board->getSquareAt(2, 1);
    Square* square3_1 = board->getSquareAt(3, 1);
    Square* square4_1 = board->getSquareAt(4, 1);
    Square* square5_1 = board->getSquareAt(5, 1);
    Square* square6_1 = board->getSquareAt(6, 1);
    Square* square7_1 = board->getSquareAt(7, 1);

    // row 1 (Black pieces)
    Square* square0_7 = board->getSquareAt(0, 7);
    Square* square1_7 = board->getSquareAt(1, 7);
    Square* square2_7 = board->getSquareAt(2, 7);
    Square* square3_7 = board->getSquareAt(3, 7);
    Square* square4_7 = board->getSquareAt(4, 7);
    Square* square5_7 = board->getSquareAt(5, 7);
    Square* square6_7 = board->getSquareAt(6, 7);
    Square* square7_7 = board->getSquareAt(7, 7);

    // row 8 (White pieces)
    Square* square0_0 = board->getSquareAt(0, 0);
    Square* square1_0 = board->getSquareAt(1, 0);
    Square* square2_0 = board->getSquareAt(2, 0);
    Square* square3_0 = board->getSquareAt(3, 0);
    Square* square4_0 = board->getSquareAt(4, 0);
    Square* square5_0 = board->getSquareAt(5, 0);
    Square* square6_0 = board->getSquareAt(6, 0);
    Square* square7_0 = board->getSquareAt(7, 0);


    // create the pieces

    // black pawns
    Pawn bPawn1 = Pawn(square0_6, BLACK);
    Pawn bPawn2 = Pawn(square1_6, BLACK);
    Pawn bPawn3 = Pawn(square2_6, BLACK);
    Pawn bPawn4 = Pawn(square3_6, BLACK);
    Pawn bPawn5 = Pawn(square4_6, BLACK);
    Pawn bPawn6 = Pawn(square5_6, BLACK);
    Pawn bPawn7 = Pawn(square6_6, BLACK);
    Pawn bPawn8 = Pawn(square7_6, BLACK);

    // black pieces
    Rook bRookL = Rook(square0_7, BLACK);
    Knight bKnightL = Knight(square1_7, BLACK);
    Bishop bBishopL = Bishop(square2_7, BLACK);
    Queen bQueen = Queen(square3_7, BLACK);
    King bKing = King(square4_7, BLACK);
    Bishop bBishopR = Bishop(square5_7, BLACK);
    Knight bKnightR = Knight(square6_7, BLACK);
    Rook bRookR = Rook(square7_7, BLACK);

    // white pawns
    Pawn wPawn1 = Pawn(square0_1, WHITE);
    Pawn wPawn2 = Pawn(square1_1, WHITE);
    Pawn wPawn3 = Pawn(square2_1, WHITE);
    Pawn wPawn4 = Pawn(square3_1, WHITE);
    Pawn wPawn5 = Pawn(square4_1, WHITE);
    Pawn wPawn6 = Pawn(square5_1, WHITE);
    Pawn wPawn7 = Pawn(square6_1, WHITE);
    Pawn wPawn8 = Pawn(square7_1, WHITE);

    // white pieces
    Rook wRookL = Rook(square0_0, WHITE);
    Knight wKnightL = Knight(square1_0, WHITE);
    Bishop wBishopL = Bishop(square2_0, WHITE);
    Queen wQueen = Queen(square3_0, WHITE);
    King wKing = King(square4_0, WHITE);
    Bishop wBishopR = Bishop(square5_0, WHITE);
    Knight wKnightR = Knight(square6_0, WHITE);
    Rook wRookR = Rook(square7_0, WHITE);


    // create each players set of pieces
    set<Piece*> blackSet = {&bPawn1, &bPawn2, &bPawn3, &bPawn4, &bPawn5,
                            &bPawn6,&bPawn7, &bPawn8, &bRookL, &bKnightL,
                            &bBishopL, &bQueen,&bKing, &bBishopR, &bKnightR,
                            &bRookR};

    set<Piece*> whiteSet = {&wPawn1, &wPawn2, &wPawn3, &wPawn4, &wPawn5,
                            &wPawn6,&wPawn7, &wPawn8, &wRookL, &wKnightL,
                            &wBishopL, &wQueen, &wKing, &wBishopR, &wKnightR,
                            &wRookR};


    // get player names, for now they are set to these defaults
    string name1 = "White";
    string name2 = "Black";

    // create players
    Player p1 = Player(name1, wKing, whiteSet);
    Player p2 = Player(name2, bKing, blackSet);

    // set players to static class variables
    player1 = &p1;
    player2 = &p2;

    // display board
    board->display();

    // run the game
    runGame();
}

void Game::finalize() {
    Board::deleteInstance();
}

void Game::runGame() {
    string move;
    bool isCheckMate = false;
    vector<bool> moveResults {false, false, false};
    Board* board = Board::getInstance();
    Player* currentPlayer = player1;


    while (!isCheckMate) {

        // make move
        moveResults = *currentPlayer->makeMove(moveResults);

        // get checkMate status from makeMove
        isCheckMate = moveResults[0];

        if (!isCheckMate) {
            // re-display the board
            board->display();
        }

        // get the next player
        currentPlayer = getNextPlayer(*currentPlayer);
    }

    if (!moveResults[1]) {
        cout << currentPlayer->getName() + " wins!\n";
    }

    cout << "Thanks for playing!";
}


Player* Game::getNextPlayer(Player& current) {
    Player* nextPlayer;

    if (&current == player1) {
        nextPlayer = player2;
    }
    else {
        nextPlayer = player1;
    }
    return nextPlayer;
}


Player* Game::getOpponentOf(Player& player) {
    Player* opponent;

    if (&player == player1) {
        opponent = player2;
    }
    else {
        opponent = player1;
    }
    return opponent;
}