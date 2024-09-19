#ifndef MOUSE_H
#define MOUSE_H
#include "iostream"
#include "Animal.h"
using namespace std; 

class Mouse: public Animal{
    public:
        Mouse();
        Mouse(int atk, int hp, string name, int equipment, string origin); 
        string getType(); 
        string getName(); 
        int getEquipment(); 
        string getOrigin(); 
};


#endif