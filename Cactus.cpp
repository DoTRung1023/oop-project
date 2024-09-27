#include <iostream>
#include "Cactus.h"
#include "Character.h"
#include "Animal.h"

Cactus::Cactus():Animal(50, 1500, "Cactus"){}

string Cactus::getName(){
    return name;
}
void Cactus::setName(string name){
    this->name = name;
}
