//
// Created by tjensen on 6/4/2020.
//

#include "Defenders.h"

Defenders::Defenders() {
    name = " D ";
}

void Defenders::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    try {
        if ((board.at(y + 1).at(x)->GetName() == " A ") && (board.at(y - 1).at(x)->GetName() == " A ")) {
            cout << "Defender at position " << x << ", " << y << " captured." << endl;
            delete board.at(y).at(x);
            board.at(y).at(x) = new Pieces();
        }
    }
    catch (...) {
        cout << "nothing here." << endl;
    }

    try {
        if ((board.at(y).at(x + 1)->GetName() == " A ") && (board.at(y).at(x - 1)->GetName() == " A ")) {
            cout << "Defender at position " << x << ", " << y << " captured." << endl;
            delete board.at(y).at(x);
            board.at(y).at(x) = new Pieces();
        }
    }
    catch (...) {
        cout << "nothing here" << endl;
    }
}
