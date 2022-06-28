//
// Created by tjensen on 6/5/2020.
//

#include "King.h"

King::King() {
    name = " K ";
}

/**
* overloaded CheckIfCaptured for the King piece.
* @param board a reference to the board object
* @param y the King's y-coordinate
* @param x the King's x-coordinate
* @param done a boolean to indicate if the game is complete
*/
void King::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    //first priority, check if the king has escaped to an edge of the board
    if ((y == 0) || (y == 6) || (x == 0) || (x == 6)) {
        cout << "The King has escaped!" << endl;
        done = true;
        return;
    }

    try {
        //first check if the King is NOT on the Throne, where he needs 4 Attackers to be captured.
        if ((y != 3) && (x != 3)) {
            //ordinary capture checking
            if (((board.at(y + 1).at(x)->GetName() == " A ") && (board.at(y - 1).at(x)->GetName() == " A ")) ||
                ((board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A "))) {

                cout << "The King has been captured." << endl;
                done = true;
                return;
            }
        }
        //else, check if he's been captured on his Throne
        else if ((board.at(y + 1).at(x)->GetName() == " A ") && (board.at(y - 1).at(x)->GetName() == " A ") &&
                 (board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A ")) {
            cout << "The King has been captured." << endl;
            done = true;
            return;
        }
    }
    catch (...) {
        //DEBUG: cout << "nothing here." << endl;
    }
}
