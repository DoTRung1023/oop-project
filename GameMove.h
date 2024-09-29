#ifndef __GAMEMOVE_H__
#define __GAMEMOVE_H__

#include <vector>
#include <iostream>
#include "Board.h"
#include "Move.h"
#include "ChessPiece.h"

using namespace std;

class GameMove{
private:
    bool turn = true; // red = true, blue = false;
    Board currentBoard;
public:
    void characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn);
    // bool playMove(Move newMove, ChessPiece* aimPiece, ChessPiece* choosePiece);
    bool playMove(Move newMove, Character* aimPiece, Character* choosePiece);
    bool nextTurn();
    vector<Move> getLegalMoves(Board currentBoard, bool turn);
    // getter
    bool getTurn();
    // void killMessage(ChessPiece killPiece);
    void killMessage(Character* killPiece);

    Board getBoard();
};

#endif