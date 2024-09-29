#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog: public Animal{
public: 
    Dog(string dog); 
    string getName();
    void setName(string name); 
    bool attack(int pieceID);
    void setAnimalType(string animalType);
};

#endif