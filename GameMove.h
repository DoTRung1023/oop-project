#ifndef __GAMEMOVE_H__
#define __GAMEMOVE_H__

#include <vector>
#include <iostream>
#include "Board.h"
#include "Move.h"

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