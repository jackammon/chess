// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <set>
#include "Piece.h"
#include "Square.h"
#include "Player.h"
#include "Game.h"

using namespace std;


Piece::Piece(Square* location, string& color)
: _location(location), _color(color) {
 if (_location != nullptr) {
     location->setOccupant(this);
 }
}


string Piece::getColor() {
    return _color;
}


Square* Piece::getLocation() {
    return _location;
}


void Piece::setLocation(Square* location) {
    _location = location;
    if (location != nullptr) {
        location->setOccupant(this);
    }
}


bool Piece::isOnSquare() {
    bool returnValue = false;
    if (_location != nullptr) {
        returnValue = true;
    }
    return returnValue;
}


bool Piece::canMoveTo(Square& location) {
    return false;
}


bool Piece::moveTo(Square& location, Player& byPlayer) {

    bool isCheck;

    // get the two squares involved in the move
    Square* moveSquare = &location;
    Square* oldSquare = this->getLocation();

    // set the move to square occupant
    moveSquare->setOccupant(this);

    // set this pieces location to the square moved to
    this->setLocation(moveSquare);

    // set the occupant of the square we moved from
    oldSquare->setOccupant(nullptr);

    // check for check
    isCheck = checkForCheck(byPlayer);

    // return true upon successful move
    return isCheck;
}

bool Piece::checkForCheck(Player& byPlayer) {

    bool isCheck = false;

    set<Piece*> pieces = *byPlayer.getPieces();

    // player2 King location
    Player* opponent = Game::getOpponentOf(byPlayer);
    Square* kingLocation = opponent->getKing()->getLocation();

    // for each piece in player1 set
    for (auto &piece : pieces) {
        // check if piece canMoveTo opponents King's location
        if (piece->canMoveTo(*kingLocation)) {
            isCheck = true;
        }
    }

    return isCheck;
}