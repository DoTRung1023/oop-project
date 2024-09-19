#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include<iostream>
using namespace std; 

class Dog: public Animal{
    public:
        //Constructor: 
        Dog();
        Dog(int atk, int hp, string name, int equipment, string origin); 

        //Getter:
        string getType(); 
        string getName(); 
        int getEquipment(); 
        string getOrigin(); 

        //Setter:
        void setName(string name); 
        void setEquipment(int equipmentID); 
        void setOrigin(string origin); 

};

#endif