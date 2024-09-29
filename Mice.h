#ifndef MICE_H
#define MICE_H
#include "Animal.h"
using namespace std; 

class Mice: public Animal{
    public:
        Mice(); 
        bool attack(int pieceID); 
};


#endif