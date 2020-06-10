//
// Created by tjensen on 6/9/2020.
//

#ifndef TAFL_FUNCTSFORMAIN_H
#define TAFL_FUNCTSFORMAIN_H

#include <iostream>
#include <vector>
#include "Pieces.h"
#include "Attackers.h"
#include "Defenders.h"
#include "King.h"

using namespace std;

void InitializeBoard(vector<vector <Pieces*>> &board);
void DisplayBoard(vector<vector <Pieces*>> &board);
void MoveXAxis(vector<vector <Pieces*>> &board, bool &done);
void MoveYAxis(vector<vector <Pieces*>> &board, bool &done);
void CheckIfCaptured(vector<vector<Pieces *>> &board, short y, short x, bool &done);

#endif //TAFL_FUNCTSFORMAIN_H
