#include <iostream>
#include "IndianElephant.h"
#include "Animal.h"

IndianElephant:: IndianElephant():Animal(400, 2500, "Indian Elephant"){}

string IndianElephant::getName(){
    return name;
}
//Setter:
void IndianElephant::setName(string name){
    this->name = name;
}
