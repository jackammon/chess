// jammon17@georgefox.edu
// Assignment 9
// 2019-04-24

#include <string>
#include <set>
#include <regex>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include "Game.h"

using namespace std;


Player::Player(string& name, King& king, set<Piece*>& pieces)
: _name(name), _king(&king), _pieces(pieces) {}


string Player::getName() {
    return _name;
}


King* Player::getKing() {
    return _king;
}


set<Piece*>* Player::getPieces() {
    return &_pieces;
}

 vector<bool>* Player::makeMove(vector<bool>& returnValue)
{
    // declare variables
    bool valid = false;
    bool checkPrintFlag = false;
    string move;
    Board* board = Board::getInstance();

    // used to validate input in the format "a1 h8" anything not matching
    // this formatting and not within the range a-h, 1-8 will be invalid
    regex standardInput("^([a-h][1-8])\\s+([a-h][1-8]=?)$");

    cout << getName() << ", enter your move: ";

    // get move
    getline(cin, move);

    // validate move input
    while (!valid) {

        // if input matches the correct format
        if (regex_match(move.begin(), move.end(), standardInput)) {

            if (move.length() == 6) {
                returnValue[1] = true;
                move.pop_back();
            }

            // separate input into two pieces
            string from = move.substr(0, 2);
            string to = move.substr(3, 5);

            // get the piece that is being moved
            // 97 and 49 are values that take the char values and make them
            // 0 - 7 values used to access the board.
            Piece *piece = board->getSquareAt(from.front() - 97,
                                              from.back() - 49)->getOccupant();

            // get square that is being moved to
            Square *square = board->getSquareAt(to.front() - 97,
                                                to.back() - 49);

            // the final check here is O(1) and checks if the selected piece
            // is one of those players pieces without iterating through the
            // players pieces set
            if (piece != nullptr && square != nullptr &&
            piece->getColor().front() == _name.front()) {

                if (piece->getLocation() == square && piece ==
                this->getKing()) {

                    returnValue[0] = true;
                    valid = true;
                }
                else if (piece->canMoveTo(*square)) {

                    // old location
                    Square* oldLocation = piece->getLocation();
                    Piece* capturedPiece = square->getOccupant();

                    // make move
                    returnValue[2] = piece->moveTo(*square, *this);

                    if (piece->checkForCheck(*Game::getOpponentOf(*this))) {

                        // reverse move
                        square->setOccupant(capturedPiece);

                        // if piece was captured move it back
                        if (capturedPiece != nullptr) {
                            capturedPiece->setLocation(square);
                        }

                        piece->setLocation(oldLocation);
                        oldLocation->setOccupant(piece);

                        cout << "You cannot put yourself in check!\n" <<
                             "Please enter a valid move: ";
                        
                        // get move
                        getline(cin, move);
                    }
                    else {
                        valid = true;
                    }
                }
                else {
                    cout << "Invalid move: please enter a valid move: ";

                    // get move
                    getline(cin, move);
                }
            }
            else {
                cout << "Invalid move: please enter a valid move: ";

                // get move
                getline(cin, move);
            }
        }
        else if (returnValue[1] && move == "=") {
            cout << "Draw!\n";
            returnValue[0] = true;
            valid = true;
        }
        // if other input
        else if (returnValue[2] && move == "#") {
            checkPrintFlag = true;
            returnValue[0] = true;
            valid = true;
        }
        else {
            cout << "Invalid move: please enter a valid move: ";

            // get move
            getline(cin, move);
        }
    }

    if (returnValue[2] && !checkPrintFlag && !returnValue[0]) {
        cout << Game::getOpponentOf(*this)->getName() + ", you are in check!\n";
    }

    return &returnValue;
}


void Player::capture(Piece& piece) {
    piece.setLocation(nullptr);
}