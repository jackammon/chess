// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <iostream>
#include "Game.h"
#include "Rook.h"
#include "Square.h"

int main(int argc, char* argv[]) {

    // starts the game
   Game::initialize();

   // free allocated memory
   Game::finalize();

   return 0;
}