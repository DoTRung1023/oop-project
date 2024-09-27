#ifndef __GAMEMOVE_H__
#define __GAMEMOVE_H__

#include <vector>
#include <iostream>

struct Board{
    int index[7][9] = { {5, -1, 0, -1, -1, -1, 8, -1, 13},
                        {-1, 6, -1, -1, -1, -1, -1, 14, -1},
                        {16, -1, 3, -1, -1, -1, 11, -1, 16},
                        {17, 16, -1, -1, -1, -1, -1, 16, 17},
                        {16, -1, 1, -1, -1, -1, 9, -1, 16},
                        {-1, 7, -1, -1, -1, -1, -1, 15, -1},
                        {2, -1, 4, -1, -1, -1, 12, -1, 10}};
};

struct Move{
    int old_X, old_Y, new_X, new_Y;
    Move(){}
    Move(int old_X, int old_Y, int new_X, int new_Y);
};

using namespace std;

class GameMove{
private:
    bool turn = true; // red = true, blue = false;
    Board currentBoard;
public:
    void characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn);
    bool playMove(Move newMove);
    bool nextTurn();
    vector<Move> getLegalMoves(Board currentBoard, bool turn);
    // getter
    bool getTurn();
    Board getBoard();
};

#endif