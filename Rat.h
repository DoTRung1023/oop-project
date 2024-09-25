#ifndef RAT_H
#define RAT_H
#include "Animal.h"

class Rat: public Animal{
public:
    Rat(); 
    string getName();
    void setName(string name); 
};


#endif