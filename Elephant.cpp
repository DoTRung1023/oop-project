#include <iostream>
#include "Elephant.h"
using namespace std; 

Elephant:: Elephant():Animal("elephant"){}

//Attack: 
// bool Elephant::attack(ChessPiece* piece){
//     if(piece->character->color != color &&
//        (piece->character->getName() == "dog" ||
//         piece->character->getName() == "fortress" ||
//         piece->character->getName() == "soldier")){
//             return true;
//         }
//     return false;
// }

bool Elephant::attack(Character* piece){
    if(piece->color != color &&
       (piece->getName() == "dog" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

Elephant::~Elephant(){
    
}

