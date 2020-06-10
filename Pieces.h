//
// Created by tjensen on 6/4/2020.
//

#ifndef TAFL_PIECES_H
#define TAFL_PIECES_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Pieces {
public:
    string GetName();
    virtual void CheckIfCaptured(vector<vector <Pieces*>> &board, short y, short x, bool &done);
protected:
    string name = " - ";
};


#endif //TAFL_PIECES_H
