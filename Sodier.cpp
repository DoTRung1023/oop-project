#include <iostream>
#include "Character.h"
#include "Soldier.h"

using namespace std;

Soldier::Soldier() : Character(50, 1500, "Soldier") {}

string Soldier::getName(){
    return name;
}

void Soldier::setName(string name){
    this->name = name;
}

Soldier:: ~Soldier(){}
