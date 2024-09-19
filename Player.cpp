#include"Player.h"
#include "BullDog.h"
#include "Shepherd.h"
#include "Poodle.h"
#include "Cacton.h"
#include"Rat.h"
#include "Cotton.h"
#include "IndianElephant.h"
#include "AfricanElephant.h"

Player:: Player(){
    maxAnimal = 8; 
    name = "Player 1"; 
    currentAnimal = 0; 

    //Create object of animals:
    BullDog* bullDog = new BullDog(); 
    Shepherd* shepherd = new Shepherd(); 
    Poodle* poodle = new Poodle(); 
    Cacton* cacton = new Cacton();
    Rat* rat = new Rat(); 
    Cotton* cotton = new Cotton(); 
    IndianElephant* indianElephant = new IndianElephant(); 
    AfricanElephant* africanElephant = new AfricanElephant(); 
    animalList = new Animal*[maxAnimal];

    
}

void Player:: addAnimal(Animal* animal){


} //Add an animal to the animalList; 
void Player:: removeAnimal(int ID){


} //Remove an animal from the animalList; 

//Getter:
string Player:: getName(){
    return name; 
}

int Player:: getID(){
    return ID; 
}

Animal** Player:: getAnimalList(){
    return animalList;
}

//Setter:
void  Player:: setName(string name){
    this->name = name; 
}
void Player:: setID(int ID){
    this->ID = ID; 
}