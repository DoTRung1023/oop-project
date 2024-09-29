#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

Player::Player(){
    //AnimalList:
    animalList = new Animal*[8];
    for(int i = 0; i<8 ; i++){//Tempt fix for dynamic allocation error in createPlayer():
        animalList[i] = nullptr; 
    }
    // make 3 types of animal
    for(int i = 0; i<8; i++){
        if(i < 3){
            animalList[i] = new Mice();
        }
        else if(i<6){
            animalList[i] = new Dog();
        }
        else{
            animalList[i] = new Elephant();    
        }
    }
    //Fortress:
    fortress = new Fortress;

    //SoldierList:
    soldierList = new Soldier*[3];
    for(int i = 0; i<3 ;i++){//Tempt fix for dynamic allocation error in createPlayer():
        soldierList[i] = new Soldier();
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

Player:: ~Player(){
    delete[] animalList; 
    delete[] soldierList;
    delete fortress;
}
