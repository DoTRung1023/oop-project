#include <iostream>
#include "GameMove.h"
#include "GameProperty.h"

using namespace std;

Move::Move(int oldX, int oldY, int newX, int newY){
    old_X = oldX;
    old_Y = oldY;
    new_X = newX;
    new_Y = newY;
}

void GameMove::characterMove(vector<Move> &possibleMoves, int current_X, int current_Y){
    if (currentBoard.index[current_X][current_Y] > -1 && currentBoard.index[current_X][current_Y] < 16){
        if(current_X>0){
            if(currentBoard.index[current_X-1][current_Y] == -1){
                possibleMoves.push_back(Move(current_X, current_Y, current_X-1, current_Y));
            }
        }
        if(current_X<7){
            if(currentBoard.index[current_X+1][current_Y] == -1){
                possibleMoves.push_back(Move(current_X, current_Y, current_X+1, current_Y));
            }
        }
        if(current_Y>0){
            if(currentBoard.index[current_X][current_Y-1] == -1){
                possibleMoves.push_back(Move(current_X, current_Y, current_X, current_Y-1));
            }
        }
        if(current_Y<9){
            if(currentBoard.index[current_X][current_Y+1] == -1){
                possibleMoves.push_back(Move(current_X, current_Y, current_X, current_Y+1));
            }
        }
    }
}

vector<Move> GameMove::getLegalMoves(Board currentBoard){
    vector<Move> possibleMoves;
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 9; ++j){
            characterMove(possibleMoves, i, j);
        }
    }
    return possibleMoves;
}

bool GameMove::playMove(Move newMove){
    vector<Move> possibleMoves = getLegalMoves(currentBoard);
    Move temp;
    for (int i = 0; i < possibleMoves.size(); ++i){
        temp = possibleMoves[i];
        if (temp.old_X == newMove.old_X && temp.old_Y == newMove.old_Y && temp.new_X == newMove.new_X && temp.new_Y == newMove.new_Y){
            currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[temp.new_Y][temp.new_Y];
            currentBoard.index[newMove.new_Y][newMove.new_Y] = -1;
            return true;
        }
    }
    return false;
}

bool GameMove::nextTurn()
{
    turn = !turn;

    return turn;
}
bool GameMove::getTurn(){
    return turn;
}

Board GameMove::getBoard(){
    return currentBoard;
}
