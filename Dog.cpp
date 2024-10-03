#include<iostream>
#include "Dog.h"
using namespace std; 

Dog:: Dog(): Animal("dog"){
}

// bool Dog::attack(ChessPiece* piece){
//     if(piece->character->color != color &&
//        (piece->character->getName() == "mice" ||
//         piece->character->getName() == "fortress" ||
//         piece->character->getName() == "soldier")){
//             return true;
//         }
//     return false;
// }

bool Dog::attack(Character* piece){
    if(piece->color != color &&
       (piece->getName() == "mice" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Dog::~Dog(){
    
}