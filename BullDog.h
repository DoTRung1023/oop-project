#ifndef BULL_DOG_H
#define BULL_DOG_H

#include <iostream>
#include "Animal.h"

using namespace std;

class BullDog: public Animal
{
public: 
    BullDog(); 
    string getName();
    void setName(string name); 
};

#endif
