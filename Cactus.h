#ifndef CACTUS_H
#define CACTUS_H

#include "Character.h"
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
