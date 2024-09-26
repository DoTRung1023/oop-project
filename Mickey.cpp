#include<iostream>
#include "Mickey.h"
#include "Animal.h"

Mickey:: Mickey():Animal(50, 2000, 0, "Mickey"){}

string Mickey::getName(){
    return name;
}
void Mickey::setName(string name){
    this->name = name;
}
