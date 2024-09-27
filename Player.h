#ifndef PLAYER_H
#define PLAYER_H
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"

#include<iostream>
using namespace std; 

class Player{
    private:
        Animal** animalList; 
        Fortress* fortress;
        Soldier** soldierList;
    public:
        Player(); //Constructor; 
        Animal** getAnimalList();
        Fortress* getFortress();
        Soldier** getSoldierList();
        ~Player(); 
};

#endif
