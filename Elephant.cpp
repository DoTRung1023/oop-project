#include <iostream>
#include "Elephant.h"
using namespace std; 

Elephant:: Elephant(string name):Animal(name){}

string Elephant::getName(){
    return name;
}
//Setter:
void Elephant::setName(string name){
    this->name = name;
}

//Attack: 
bool Elephant:: attack(int pieceID){
    return 0; 
}