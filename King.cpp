//
// Created by tjensen on 6/5/2020.
//

#include "King.h"

King::King() {
    name = " K ";
}

void King::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    if ((y != 3) && (x != 3)) {

        if (((board.at(y + 1).at(x)->GetName() == " A ") && (board.at(y - 1).at(x)->GetName() == " A ")) ||
        ((board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A "))) {

            cout << "The King has been captured." << endl;
            done = true;
        }

        else if ((board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A ")) {
            cout << "The King has been captured." << endl;
            done = true;
        }

        else {
            return;
        }
    }

    else if ((y == 0) || (y == 6) || (x == 0) || (x == 6)) {
        cout << "The King has escaped!" << endl;
        done = true;
    }

    else {
        if ((board.at(y + 1).at(x)->GetName() == " A ") && (board.at(y - 1).at(x)->GetName() == " A ") &&
        (board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A ")) {
            cout << "The King has been captured." << endl;
            done = true;
        }
    }
}
