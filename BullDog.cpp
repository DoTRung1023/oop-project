#include<iostream>
#include "Animal.h"
#include "Character.h"
#include "BullDog.h"

using namespace std;

BullDog:: BullDog():Animal(250,1000, "BullDog"){}
string BullDog::getName(){
    return name;
}
void BullDog::setName(string name){
    this->name = name;
}
