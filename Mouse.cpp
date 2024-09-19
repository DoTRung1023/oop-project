#include<iostream>
#include"Mouse.h"


Mouse:: Mouse(){
    this->atk = 0; 
    this->hp = 0;
    this->name = "null"; 
    this->equipmentID = 0; 
    this->origin = "null"; 
    this->type = "ms"; 
}
Mouse:: Mouse(int atk, int hp, string name, int equipment, string origin): Animal(atk, hp, name, equipment, origin){
    type = "ms"; 

}
string Mouse:: getType(){
    return Animal::getType(); 
}

string Mouse:: getName(){
    return Animal::getName(); 
}
int Mouse:: getEquipment(){
    return Animal::getEquipment(); 
}
string Mouse:: getOrigin(){
    return Animal::getOrigin(); 
}