#ifndef FORTRESS_H
#define FORTRESS_H
#include "ChessPiece.h"


class Fortress: public ChessPiece
{
public:
    Fortress();
    string getName();
    void setName(string name); 

};

#endif
