#include <iostream>
#include "Elephant.h"
using namespace std; 

Elephant:: Elephant():Animal("elephant"){}

bool Elephant::attack(Character* piece){
    if(piece != nullptr && piece->color != color &&
       (piece->getName() == "dog" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Elephant::~Elephant(){
    
}

