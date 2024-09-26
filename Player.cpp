#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"

Player:: Player():Player(""){}
Player::Player(string name): name(name){
    animalList = new Animal*[8];
    for(int i = 0; i<8 ; i++){//Tempt fix for dynamic allocation error in createPlayer():
        animalList[i] = nullptr; 
    }
    fortress = new Fortress;
    soldierList = new Soldier*[3];
    for(int i = 0; i<3 ;i++){//Tempt fix for dynamic allocation error in createPlayer():
        soldierList[i] = nullptr; 
    }
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

Player:: ~Player(){
    for(int i = 0; i<8; i++){
        delete animalList[i]; 
    }
    for(int i = 0;i <3; i++){
        delete soldierList[i];
    }
    delete[] animalList; 
    delete[] soldierList; 
    delete fortress; 

}