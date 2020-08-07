//
// Created by tjensen on 6/5/2020.
//

#include "King.h"

King::King() {
    name = " K ";
}

void King::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    //first priority, check if the king has escaped to an edge of the board
    if ((y == 0) || (y == 6) || (x == 0) || (x == 6)) {
        cout << "The King has escaped!" << endl;
        done = true;
        return;
    }

    try {
        /*first check if the King is NOT on the Throne, where he needs 4 Attackers to be captured. I've heard "not"
         * comparisons are more efficient than "same" comparisons. */
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
