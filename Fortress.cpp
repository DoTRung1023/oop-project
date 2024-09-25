#include "Fortress.h"
#include "ChessPiece.h"

using namespace std;

Fortress::Fortress(): ChessPiece(0, 1000, 0, "Fortress", 17) {}

string Fortress::getName(){
    return name;
}

void Fortress::setName(string name){
    this->name = name;
}

