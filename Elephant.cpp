#include<iostream>
#include "Elephant.h"

Elephant:: Elephant(int atk, int hp, string name, int equipment, string origin): Animal(atk, hp, name, equipment, origin){
    type = "dg"; 
}


Elephant:: Elephant(){
    this->atk = 0; 
    this->hp = 0;
    this->name = "null"; 
    this->equipmentID = 0; 
    this->origin = "null"; 
    this->type = "el"; 
}


string Elephant:: getType(){
    return Animal::getType(); 
}

string Elephant:: getName(){
    return Animal::getName(); 
}
int Elephant:: getEquipment(){
    return Animal::getEquipment(); 
}
string Elephant:: getOrigin(){
    return Animal::getOrigin(); 
}