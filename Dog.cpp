#include<iostream>
#include "Dog.h"
using namespace std; 

Dog:: Dog(string name): Animal(name){}

string Dog:: getName(){
    return this->name; 
}



void Dog:: setName(string name){
   this->name = name;  
}

bool Dog::attack(int pieceID){
    return 0; 
}

