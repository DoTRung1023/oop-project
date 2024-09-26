#ifndef __GAMEMOVE_H__
#define __GAMEMOVE_H__

#include <vector>
#include <iostream>

using namespace std;

struct GameMove
{
    bool playMove(Move newMove);
    bool nextTurn();

};

#endif