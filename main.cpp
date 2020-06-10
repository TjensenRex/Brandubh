#include <iostream>
#include <vector>
#include "Pieces.h"
#include "functsForMain.h"

using namespace std;

int main() {
    vector<vector<Pieces*>> board (7);
    bool done = false;
    bool moved = false;
    char input;

    /*FIXME: pieces cannot move to right side or bottom of board without terminating the game. This seems to be caused by
     * the CheckIfCaptured function call checking the names of Pieces beyond the board's edge. Figure out an elegant
     * way to solve this.*/

    cout << "Welcome to this virtual version of Brandubh, in the Tafl family of games. This game is played with two teams:"
    << "\nAttackers, represented by an 'A' and Defenders, represented by a 'D'. The goal of the Defenders is to get their\n"
       "King (represented by 'K') to the edge of the board. The board is 7 x 7, represented here by a grid with coordinates\n"
       "from 0-6 horizontally (x-values) and vertically (y-values). Pieces may be captured by getting two of the opposing\n"
       "team's pieces on either side of it. For this version, the King may not participate in captures. The center square\n"
       " (3, 3) is called the Throne, and the King cannot be captured there unless there is an Attacker on each side."
       << endl << endl;

    InitializeBoard(board);

    while (!done)
    {
        cout << "Find the piece you would like to move. Will it be an "
                "\n(a) horizontal or "
                "\n(b) vertical \nmovement?" << endl;
        moved = false;

        while (!moved)
        {
            cin >> input;
            if (input == 'a')
            {
                MoveXAxis(board, done);
                moved = true;
            }
            else if (input == 'b')
            {
                MoveYAxis(board, done);
                moved = true;
            }
            else {
                cout << "Invalid choice. Please type 'a' or 'b'." << endl;
            }
        }
    }

    return 0;
}
