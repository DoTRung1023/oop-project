#include "Character.h"

Character:: Character(int atk, int hp):atk(atk), hp(hp){}
Character:: Character(){
    this->atk = 0; 
    this->hp = 0; 
}


void Character:: status(Character* character){
    return; 
}

int Character:: attack(Character* target){
    return 0; 
}
