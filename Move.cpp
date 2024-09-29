#include "Move.h"
#include <iostream>

using namespace std;

// define struct move
Move::Move(int oldX, int oldY, int newX, int newY){
    old_X = oldX;
    old_Y = oldY;
    new_X = newX;
    new_Y = newY;
}