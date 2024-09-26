#include<iostream>
#include "Poodle.h"
#include "Animal.h"

Poodle:: Poodle():Animal(100,600, 0,"Poodle"){}//int atk, int hp, string name, int equipment

string Poodle::getName(){
    return name;
}
void Poodle::setName(string name){
    this->name = name;
}
