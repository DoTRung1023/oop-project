#ifndef PLAYER_H
#define PLAYER_H
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"

#include<iostream>
using namespace std; 

class Player{
    private:
        string name;
        Animal** animalList; 
        Fortress* fortress;
        Soldier** soldierList;
    public:
        Player(); //Constructor; 
        Player(string Name);
        Animal** getAnimalList();
        Fortress* getFortress();
        Soldier** getSoldierList();
        void setName(string name);
        string getName();
        ~Player(); 
};

#endif
