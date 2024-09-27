#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"
#include "BullDog.h"
#include "Poodle.h"
#include "Shepherd.h"
#include "Mickey.h"
#include "Rat.h"
#include "Cactus.h"
#include "IndianElephant.h"
#include "AfricanElephant.h"

Player::Player(){
    //AnimalList:
    animalList = new Animal*[8];
    for(int i = 0; i<8 ; i++){//Tempt fix for dynamic allocation error in createPlayer():
        animalList[i] = nullptr; 
    }
    animalList[0] = new BullDog;
    animalList[1] = new Poodle;
    animalList[2] = new Shepherd;
    animalList[3] = new Mickey;
    animalList[4] = new Rat;
    animalList[5] = new Cactus;
    animalList[6] = new IndianElephant;
    animalList[7] = new AfricanElephant;

    //Fortress:
    fortress = new Fortress;

    //SoldierList:
    soldierList = new Soldier*[3];
    for(int i = 0; i<3 ;i++){//Tempt fix for dynamic allocation error in createPlayer():
        soldierList[i] = new Soldier();
        soldierList[i]->setEquipment(i+1); 
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
