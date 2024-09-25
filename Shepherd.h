#ifndef SHEPHERD_H
#define SHEPHERD_H
#include "Animal.h"

class Shepherd: public Animal{
public: 
    Shepherd(); 
    string getName();
    void setName(string name); 
};

#endif