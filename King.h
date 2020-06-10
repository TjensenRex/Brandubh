//
// Created by tjensen on 6/5/2020.
//

#ifndef TAFL_KING_H
#define TAFL_KING_H

#include "Defenders.h"
class King : public Defenders {
public:
    King();
    void CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done) override;
};


#endif //TAFL_KING_H
