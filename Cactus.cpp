#include<iostream>
#include "Cactus.h"
#include "ChessPiece.h"
#include "Animal.h"

Cactus::Cactus():Animal(50, 1500, 0, "Cactus", -1){}

string Cactus::getName(){
    return name;
}
void Cactus::setName(string name){
    this->name = name;
}
