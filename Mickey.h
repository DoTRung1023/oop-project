#ifndef MICKEY_H
#define MICKEY_H
#include "Animal.h"

class Mickey: public Animal{
public:
    Mickey(); 
    string getName();
    void setName(string animalName); 
};



#endif
