//Implementation of Animal.h
#include <iostream>
#include "Animal.h"
#include "Character.h"
using namespace std; 

//Optional Constructor
Animal::Animal(string name):Character(name){}

Animal:: Animal(){
    this->name = " "; 
}//Default Constructor

Animal:: ~Animal(){}