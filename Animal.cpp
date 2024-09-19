#include<iostream>
#include "Animal.h"

void Animal:: info(Animal* animal){
    cout << "Name: " << name << "HP: " << hp << "ATK: " << atk  << endl; 
    cout << "Equipment: " << equipmentID; 
}

Animal:: Animal(int atk, int hp, string name, int equipmentID, string origin): Character(atk, hp){//Optional Constructor
    this->name = name; 
    this->equipmentID = equipmentID; 
    this->origin = origin; 
    this->type = "null"; 

}

Animal:: Animal(){//Default Constructor
    Character::atk = 0; 
    Character::hp = 0; 
    this->name = ""; 
    this->equipmentID = 0; 
    this->origin = ""; 
    this->type = ""; 
}

string Animal:: getName(){
    return name; 
}
int Animal:: getEquipment(){
    return equipmentID; 
}
string Animal:: getOrigin(){
    return origin; 
}
string Animal:: getType(){
    return type; 
}

void Animal:: setName(string name){
    this->name = name;
}
void Animal:: setEquipment(int equipmentID){
    this->equipmentID = equipmentID;
}
void Animal:: setOrigin(string origin){
    this->origin = origin; 
}

void Animal:: status(Character* character){
    cout << "Name: " << this->name << "HP: " << this->hp << "Equipment: " << this->equipmentID << "Type: "<< this->type << "Origin: " << this->origin << endl; 
    return; 
}

int Animal:: attack(Character* target){
    return 0; 
}

string Animal:: getEquipmentName(int weaponID){
    string result = ""; 
    switch(weaponID){
        case 1:
            result = "Staff"; 
            break;
        case 2:
            result = "Knife"; 
            break;
        case 3:
            result = "Hammer"; 
            break;
        case 4:
            result = "Arrow"; 
            break;
        case 5:
            result = "Armour"; 
            break;
        case 6:
            result = "Round Shield"; 
            break;
        case 7:
            result = "Spike Shield"; 
            break;
        case 8:
            result = "Heater Shield"; 
            break;
        default:
            result = "null"; 
            break;
    }   
    return result; 
}