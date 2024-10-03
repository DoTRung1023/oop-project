#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"

class Elephant: public Animal{
    public:
        Elephant(); 
        bool attack(Character* piece);
        ~Elephant();
};

#endif