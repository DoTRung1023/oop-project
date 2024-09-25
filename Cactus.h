#ifndef CACTUS_H
#define CACTUS_H

#include "ChessPiece.h"
#include "Animal.h"

using namespace std;

class Cactus: public Animal
{
public:
    Cactus(); 
    string getName();
    void setName(string name); 
};



#endif
