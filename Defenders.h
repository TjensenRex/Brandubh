//
// Created by tjensen on 6/4/2020.
//

#ifndef TAFL_DEFENDERS_H
#define TAFL_DEFENDERS_H

#include <iostream>
#include <vector>
#include "Pieces.h"

using namespace std;

class Defenders : public Pieces {
public:
    Defenders();
    void CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) override;
};


#endif //TAFL_DEFENDERS_H
