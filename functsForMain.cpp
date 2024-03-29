//
// Created by tjensen on 6/9/2020.
//

#include "functsForMain.h"

/**
* Creates the board to start the game.
* @param board a 2-D vector of Pieces pointers to represent the board
*/
void InitializeBoard(vector<vector <Pieces*>> &board) {
    //Like it says, this sets up the board at the beginning of the game.
    for (vector<Pieces*> &row : board) {
        row.resize(7);
        //row.assign(7, new Pieces()); <- I have no idea why this doesn't work for filling the board with Pieces.
    }
    for (vector<Pieces*> &row : board) {
        for (Pieces* &piece : row) {
            piece = new Pieces();
        }
    }

    //for accessing specific elements, first .at is the y axis and second .at is the x axis
    //Defenders first
    delete board[3][2];
    board[3][2] = new Defenders();
    delete board[2][3];
    board[2][3] = new Defenders();
    delete board[3][4];
    board[3][4] = new Defenders();
    delete board[4][3];
    board[4][3] = new Defenders();
    delete board[3][3];
    board[3][3] = new King();

    //Attackers
    delete board[3][0];
    board[3][0] = new Attackers();
    delete board[3][1];
    board[3][1] = new Attackers();
    delete board[3][5];
    board[3][5] = new Attackers();
    delete board[3][6];
    board[3][6] = new Attackers();
    delete board[0][3];
    board[0][3] = new Attackers();
    delete board[1][3];
    board[1][3] = new Attackers();
    delete board[5][3];
    board[5][3] = new Attackers();
    delete board[6][3];
    board[6][3] = new Attackers();

    DisplayBoard(board);
}

/**
* Displays the board to cout.
* @param board the board to display.
*/
void DisplayBoard(vector<vector <Pieces*>> &board) {
    short yAxis = 0;
    //display coordinate key above the board
    cout << "  0  1  2  3  4  5  6 " << endl;
    //this loop puts a coordinate key on either side of the board
    for (vector<Pieces*> &row : board) {
        cout << yAxis;
        for (Pieces* &piece : row) {
            cout << piece->GetName();
        }
        cout << yAxis << endl;
        yAxis += 1;
    }
    //display coordinate key below the board
    cout << "  0  1  2  3  4  5  6 " << endl;
    cout << endl;
}

/**
* Function for movement along the x-axis.
* @param board a reference to the board.
* @param done tracks whether the game is finished
* @param isAttacker indicates which player's turn it is. true = Attacker's turn, false = Defender's turn
*/
void MoveXAxis(vector<vector <Pieces*>> &board, bool &done, bool &isAttacker) {
    
    short x;
    short x2;
    short y;
    short i;
    //the ready boolean tells the game to pass the turn to the next player
    bool ready = false;
    Pieces* temp;

    while (!ready) {
        cout << "Enter the coordinates of the piece you wish to move.\nX-value:" << endl;
        cin >> x;
        if (x >= 7 || x < 0) continue; //restarts the loop
        cout << "Y-value:" << endl;
        cin >> y;
        if (y >= 7 || y < 0) continue; //restarts the loop

        if (isAttacker) {
            if (board.at(y).at(x)->GetName() != " A ") {
                cout << "Invalid piece. Please try again." << endl;
                continue;
            }
        }
        else {
            if ((board.at(y).at(x)->GetName() != " D ") && (board.at(y).at(x)->GetName() != " K ")) {
                cout << "Invalid piece. Please try again." << endl;
                continue;
            }
        }

        cout << board.at(y).at(x)->GetName() << " selected. " << endl;

        cout << "Enter the X-value this piece is moving to, or type '7' to reset your turn:" << endl;
        cin >> x2;

        //The next two loops check if there's a piece in the way
        if (x2 < x) {
            for (i = x2; i < x; ++i) {
                if (board.at(y).at(i)->GetName() != " - ") {
                    cout << "You cannot move through another piece. Please make another choice." << endl;
                    cin >> x2;
                    break;
                }
            }
        }

        else if (x2 < 7) {
            for (i = x + 1; i < (x2 + 1); ++i) {
                if (board.at(y).at(i)->GetName() != " - ") {
                    cout << "You cannot move through another piece. Please make another choice."<< endl;
                    cin >> x2;
                    break;
                }
            }
        }
        ready = (x2 != 7);      //if the user entered 7, restart the process without passing the turn
    }

    temp = board.at(y).at(x2);
    board.at(y).at(x2) = board.at(y).at(x);
    board.at(y).at(x) = temp;

    //is this part needed since temp will soon move out of scope?
    temp = nullptr;
    delete temp;

    CheckIfCaptured(board, y, x2, done);

    DisplayBoard(board);
}

/**
* Function for movement along the y-axis.
* @param board a reference to the board.
* @param done tracks whether the game is finished
* @param turnTracker indicates which player's turn it is. true = Attacker's turn, false = Defender's turn
*/
void MoveYAxis(vector<vector<Pieces *>> &board, bool &done, bool &isAttacker) {
    
    short x;
    short y;
    short y2;
    short i;
    bool ready = false;
    Pieces* temp;

    while (!ready) {
        cout << "Enter the coordinates of the piece you wish to move.\nX-value:" << endl;
        cin >> x;
        if (x >= 7 || x < 0) continue; //restarts the loop
        cout << "Y-value:" << endl;
        cin >> y;
        if (y >= 7 || y < 0) continue; //restarts the loop

        if (isAttacker) {
            if (board.at(y).at(x)->GetName() != " A ") {
                cout << "Invalid piece. Please try again." << endl;
                continue;
            }
        }
        else {
            if ((board.at(y).at(x)->GetName() != " D ") && (board.at(y).at(x)->GetName() != " K ")) {
                cout << "Invalid piece. Please try again." << endl;
                continue;
            }
        }

        cout << board.at(y).at(x)->GetName() << " selected. " << endl;

        cout << "Enter the Y-value this piece is moving to, or type '7' to reset your turn:" << endl;
        cin >> y2;

        //check if there's a piece in the way
        if (y2 < y) {
            for (i = y2; i < y; ++i) {
                if (board.at(i).at(x)->GetName() != " - ") {
                    cout << "You cannot move through another piece. Please make another choice." << endl;
                    cin >> y2;
                    break;
                }
            }
        }

        else if (y2 < 7) {
            for (i = y + 1; i < (y2 + 1); ++i) {
                if (board.at(i).at(x)->GetName() != " - ") {
                    cout << "You cannot move through another piece. Please make another choice."<< endl;
                    cin >> y2;

                    break;
                }
            }
        }
        //remember that if a person inputs 7, their turn restarts
        ready = (y2 != 7);
    }

    temp = board.at(y2).at(x);
    board.at(y2).at(x) = board.at(y).at(x);
    board.at(y).at(x) = temp;

    //is this part needed?
    temp = nullptr;
    delete temp;

    CheckIfCaptured(board, y2, x, done);

    DisplayBoard(board);
}

/**
* Checks if pieces around the moved piece have been captured.
* @param board reference to the board object.
* @param y the y-coordinate of the moved piece.
* @param x the x-coordinate of the moved piece.
* @param done a boolean to check if the game is done.
*/
void CheckIfCaptured(vector<vector<Pieces *>> &board, short y, short x, bool &done) {
    //after movement, checks if any of the surrounding pieces have been captured.
    short i;
    //checks for capture along the x-axis of the moved piece, being careful to ignore numbers beyond board's indices.
    for (i = x - 1; i <= (x + 1); ++i) {
        if ((i < 0) || (i > 6)) {
            continue;
        }

        else {      //This is not a recursive call, it invokes the member function of the same name.
            board.at(y).at(i)->CheckIfCaptured(board, y, i, done);
        }
    }
    //check for capture along the piece's y-axis.
    for (i = y - 1; i <= (y + 1); ++i) {
        if ((i < 0) || (i > 6)) {
            continue;
        }

        else {
            board.at(i).at(x)->CheckIfCaptured(board, i, x, done);
        }
    }
}
