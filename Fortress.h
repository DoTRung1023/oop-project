#ifndef FORTRESS_H
#define FORTRESS_H
#include "Character.h"

class Fortress: public Character
{
public:
    Fortress();
    bool attack(Character* piece);
    ~Fortress(); 
};

#endif
