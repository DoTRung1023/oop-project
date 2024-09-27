#include<iostream>
#include "Shepherd.h"
#include "Animal.h"

Shepherd:: Shepherd():Animal(200,800, "Shepherd"){}
string Shepherd::getName(){
    return name;
}
void Shepherd::setName(string name){
    this->name = name;
}
