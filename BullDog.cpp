#include<iostream>
#include "Animal.h"
#include "ChessPiece.h"
#include "BullDog.h"

using namespace std;

BullDog:: BullDog():Animal(250,1000, 0, "BullDog", -1){}
string BullDog::getName(){
    return name;
}
void BullDog::setName(string name){
    this->name = name;
}
