#include<iostream>
#include "Dog.h"

Dog:: Dog(int atk, int hp, string name, int equipment, string origin): Animal(atk, hp, name, equipment, origin){
    type = "dg"; 
}


Dog:: Dog(){
    this->atk = 0; 
    this->hp = 0;
    this->name = "null"; 
    this->equipmentID = 0; 
    this->origin = "null"; 
    this->type = "dg"; 
}


string Dog:: getType(){
    return Animal::getType(); 
}

string Dog:: getName(){
    return Animal::getName(); 
}
int Dog:: getEquipment(){
    return Animal::getEquipment(); 
}
string Dog:: getOrigin(){
    return Animal::getOrigin(); 
}

void Dog:: setName(string name){
    this->name = name;
}
void Dog:: setEquipment(int equipmentID){
    this->equipmentID = equipmentID;
}
void Dog:: setOrigin(string origin){
    this->origin = origin; 
}