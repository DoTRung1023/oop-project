#include <iostream>
#include "AfricanElephant.h"


AfricanElephant:: AfricanElephant():Animal(350, 2700, 0, "African Elephant", -1){}

string AfricanElephant::getName(){
    return name;
}
//Setter:
void AfricanElephant::setName(string name){
    this->name = name;
}
