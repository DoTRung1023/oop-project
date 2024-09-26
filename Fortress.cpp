#include "Fortress.h"
#include "Character.h"

using namespace std;

Fortress::Fortress(): Character(0, 1000, 0, "Fortress") {}

string Fortress::getName(){
    return name;
}

void Fortress::setName(string name){
    this->name = name;
}

Fortress::~Fortress(){}