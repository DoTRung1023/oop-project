#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "Animal.h"
#include<iostream>
using namespace std; 

class Elephant: public Animal{
    public:
        Elephant();
        Elephant(int atk, int hp, string name, int equipment, string origin); 
        string getType(); 
        string getName(); 
        int getEquipment(); 
        string getOrigin(); 
};

#endif