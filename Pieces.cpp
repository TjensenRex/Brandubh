//
// Created by tjensen on 6/4/2020.
//

#include "Pieces.h"


string Pieces::GetName() {
    return name;
}

void Pieces::CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) {
    //DEBUG: cout << "no piece here to capture!" << endl;
}