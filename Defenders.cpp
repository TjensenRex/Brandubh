//
// Created by tjensen on 6/4/2020.
//

#include "Defenders.h"

Defenders::Defenders() {
    name = " D ";
}

/**
* overloaded CheckIfCaptured function for Defenders.
* @param board reference to the board object.
* @param y the piece's y-coordinate.
* @param x the piece's x-coordinate.
* @param done indicates whether the game is done.
*/
void Defenders::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    try {
        //checking if an enemy piece is above and below this one
        if ((board.at(y + 1).at(x)->GetName() == " A ") && (board.at(y - 1).at(x)->GetName() == " A ")) {
            cout << "Defender at position " << x << ", " << y << " captured." << endl;
            delete board.at(y).at(x);
            board.at(y).at(x) = new Pieces();
        }
    }
    catch (...) {
        //DEBUG: cout << "nothing here." << endl;
    }

    try {
        //checking if an enemy piece is on both sides of this one
        if ((board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A ")) {
            cout << "Defender at position " << x << ", " << y << " captured." << endl;
            delete board.at(y).at(x);
            board.at(y).at(x) = new Pieces();
        }
    }
    catch (...) {
        //DEBUG: cout << "nothing here" << endl;
    }
}
