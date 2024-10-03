#include<iostream>
#include "Dog.h"
using namespace std; 

Dog:: Dog(): Animal("dog"){
}
bool Dog::attack(Character* piece){
    if(piece != nullptr && piece->color != color &&
       (piece->getName() == "mice" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Dog::~Dog(){
    
}