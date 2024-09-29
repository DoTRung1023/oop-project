#include "Fortress.h"
#include "Character.h"

using namespace std;

Fortress::Fortress(): Character("fortress") {}

bool Fortress::attack(Character* piece){
    return false;
}


Fortress::~Fortress(){}