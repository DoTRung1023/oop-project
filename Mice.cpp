#include "iostream"
#include "Mice.h"
using namespace std; 

Mice:: Mice():Animal("mice"){}

bool Mice::attack(Character* piece){
    if(piece != nullptr && piece->color != color &&
       (piece->getName() == "elephant" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Mice::~Mice(){
    
}