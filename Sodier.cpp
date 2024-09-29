#include <iostream>
#include "Character.h"
#include "Soldier.h"

using namespace std;

Soldier::Soldier() : Character("soldier") {}

bool Soldier::attack(Character* piece){
    return false;
}

Soldier:: ~Soldier(){}
