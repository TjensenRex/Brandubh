//
// Created by tjensen on 6/4/2020.
//

#include "Attackers.h"

Attackers::Attackers() {
    name = " A ";
}

void Attackers::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    try {
        if ((board.at(y + 1).at(x)->GetName() == " D ") && (board.at(y - 1).at(x)->GetName() == " D ")) {
            cout << "Attacker at position " << x << ", " << y << " captured." << endl;
            delete board.at(y).at(x);
            board.at(y).at(x) = new Pieces();
        }
    }
    catch (...) {
        //DEBUG: cout << "nothing here." << endl;
    }

    try {
        if ((board.at(y).at(x + 1)->GetName() == " D ") && (board.at(y).at(x - 1)->GetName() == " D ")) {
            cout << "Attacker at position " << x << ", " << y << " captured." << endl;
            delete board.at(y).at(x);
            board.at(y).at(x) = new Pieces();
        }
    }
    catch (...) {
        //DEBUG: cout << "nothing here" << endl;
    }
}
