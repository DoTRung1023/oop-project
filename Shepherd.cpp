#include<iostream>
#include "Shepherd.h"
#include "Animal.h"

Shepherd:: Shepherd():Animal(200,800, 0, "Shepherd", -1){}
string Shepherd::getName(){
    return name;
}
void Shepherd::setName(string name){
    this->name = name;
}
