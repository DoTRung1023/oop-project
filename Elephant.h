#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"

class Elephant: public Animal{
    public:
        Elephant(string name); 
        string getName();
        void setName(string name); 
        bool attack(int pieceID);
};

#endif