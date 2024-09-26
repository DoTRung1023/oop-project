#ifndef FORTRESS_H
#define FORTRESS_H
#include "Character.h"

class Fortress: public Character
{
public:
    Fortress();
    string getName();
    void setName(string name); 
    ~Fortress(); 

};

#endif
