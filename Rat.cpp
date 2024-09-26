#include "Rat.h"
#include "Animal.h"

Rat:: Rat():Animal(50, 1700, 0, "Rat"){}
string Rat::getName(){
    return name;
}
void Rat::setName(string name){
    this->name = name;
}
