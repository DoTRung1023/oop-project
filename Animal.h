#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
using namespace std; 

#include "Character.h"

class Animal: public Character{
    protected:
        string name; 
        int equipmentID; 
        string origin; 
        string type;
    public:
        Animal(int atk, int hp, string name, int equipmentID, string origin); 
        Animal(); 
        virtual void info(Animal* animal); 
        virtual string getName(); 
        virtual int getEquipment(); 
        virtual string getOrigin(); 
        virtual string getType();

        virtual void setName(string name); 
        virtual void setEquipment(int equipmentID); 
        virtual void setOrigin(string origin); 
        void status(Character* character); 

        int attack(Character* target);
        string  getEquipmentName(int weaponID);

};

#endif
