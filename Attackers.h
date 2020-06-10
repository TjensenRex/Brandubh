//
// Created by tjensen on 6/4/2020.
//

#ifndef TAFL_ATTACKERS_H
#define TAFL_ATTACKERS_H

#include <iostream>
#include <vector>
#include "Pieces.h"

using namespace std;

class Defenders;
class Attackers : public Pieces {
public:
    Attackers();
    void CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) override;
};


#endif //TAFL_ATTACKERS_H
