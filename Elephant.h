#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"

class Elephant: public Animal{
    public:
        Elephant(); 
        bool attack(int pieceID);
};

#endif