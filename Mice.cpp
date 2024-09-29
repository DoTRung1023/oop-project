#include "iostream"
#include "Mice.h"
using namespace std; 

Mice:: Mice():Animal("mice"){}

// bool Mice::attack(ChessPiece* piece){
//     if(piece->character->color != color &&
//        (piece->character->getName() == "elephant" ||
//         piece->character->getName() == "fortress" ||
//         piece->character->getName() == "soldier")){
//             return true;
//         }
//     return false;
// }

bool Mice::attack(Character* piece){
    if(piece->color != color &&
       (piece->getName() == "elephant" ||
        piece->getName() == "fortress" ||
        piece->getName() == "soldier")){
            return true;
        }
    return false;
}

