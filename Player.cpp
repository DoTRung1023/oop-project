#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"

Player:: Player():Player(""){}
Player::Player(string name): name(name){
    animalList = new Animal*[8];
    fortress = new Fortress;
    soldierList = new Soldier*[2];
}
Animal** Player::getAnimalList(){
    return animalList;
}
Fortress* Player::getFortress(){
    return fortress;
}
Soldier** Player::getSoldierList(){
    return soldierList;
}

void Player::setName(string name){
    this->name = name;
}
string Player::getName(){
    return name;
}
