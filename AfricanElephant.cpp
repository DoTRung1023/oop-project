#include <iostream>
#include "AfricanElephant.h"
#include "Character.h"

AfricanElephant:: AfricanElephant():Animal(350, 2700, "African Elephant"){}

string AfricanElephant::getName(){
    return name;
}
//Setter:
void AfricanElephant::setName(string name){
    this->name = name;
}
