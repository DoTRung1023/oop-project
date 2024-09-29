#include <iostream>
#include <vector>
#include "GameMove.h"
#include "GameProperty.h"

using namespace std;

// get possible move and push in the vector
void GameMove::characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn){
    // true = red, false = blue
    bool validColor = currentBoard.index[current_X][current_Y] < 8;
    // check 4 direction to get possible move
    if (currentBoard.index[current_X][current_Y] > -1 && currentBoard.index[current_X][current_Y] < 16 && validColor == turn){
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
// search all board to get possible move
vector<Move> GameMove::getLegalMoves(Board currentBoard, bool turn){
    vector<Move> possibleMoves;
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 9; ++j){
            if(currentBoard.index[i][j] > -1 && currentBoard.index[i][j] < 16){
                characterMove(possibleMoves, i, j, turn);
            }
        }
    }
    return possibleMoves;
}
// move the animals
bool GameMove::playMove(Move newMove){
    vector<Move> possibleMoves = getLegalMoves(currentBoard, turn);
    Move temp;
    for (int i = 0; i < possibleMoves.size(); i++){
        temp = possibleMoves[i];
        // if the move matches a possible move -> move
        if (temp.old_X == newMove.old_X && temp.old_Y == newMove.old_Y && temp.new_X == newMove.new_X && temp.new_Y == newMove.new_Y){
            currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[newMove.old_X][newMove.old_Y];
            currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
            return true;
        }
    }
    return false;
}
// switch turn
bool GameMove::nextTurn()
{
    turn = !turn;

    return turn;
}
// getter
bool GameMove::getTurn(){
    return turn;
}

Board GameMove::getBoard(){
    return currentBoard;
}
