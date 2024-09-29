#include "iostream"
#include "Mice.h"
using namespace std; 

Mice:: Mice(string name):Animal(name){}

string Mice::getName(){
    return name;
}
void Mice::setName(string name){
    this->name = name;
}

bool Mice:: attack(int pieceID){
    return 0; 
}