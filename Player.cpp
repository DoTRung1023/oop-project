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
    Player("Player 00", 0);
}//Default Constructor

Player:: Player(string name, int id){
    maxAnimal = 8; 
    this->name = name; 
    currentAnimal = 0; 
    ID = id; 
    animalList = new Animal*[maxAnimal];

    //Create object of animals:
    BullDog* bullDog = new BullDog(); 
    Shepherd* shepherd = new Shepherd(); 
    Poodle* poodle = new Poodle(); 
    Cacton* cacton = new Cacton();
    Rat* rat = new Rat(); 
    Cotton* cotton = new Cotton(); 
    IndianElephant* indianElephant = new IndianElephant(); 
    AfricanElephant* africanElephant = new AfricanElephant(); 

    addAnimal(bullDog); 
    addAnimal(shepherd); 
    addAnimal(poodle); 
    addAnimal(cacton); 
    addAnimal(rat); 
    addAnimal(cotton); 
    addAnimal(indianElephant); 
    addAnimal(africanElephant); 
} //Optional Constructor

bool Player:: addAnimal(Animal* animal){
    if(currentAnimal < maxAnimal){
        return false; 
    }
    else{
        animalList[currentAnimal] = animal; 
        currentAnimal++;
        return true;  
    }
    

} //Add an animal to the animalList; 

bool Player:: removeAnimal(string name){//Ghi vào remove index cái index đã xóa
    for(int i = 0; i<currentAnimal; i++){
        if(isInRemoveList(i)){//If the animal is already removed then return continue
            continue; 
        }
        else{
            if(name.compare(animalList[i]->getName())){//If the animal is in the list then return true
                delete animalList[i]; 
                return true;
            }
        }
        return false; //Return false otherwise. 
    }

} //Remove an animal from the animalList; 


bool Player:: isInRemoveList(int index){
    for(int i = 0; i<currentAnimal; i++){
        if(index == i){
            return true; 
        }
    }
    return false; 
}

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

Animal* Player:: getAnimal(string animalName){
    for(int i = 0; i < currentAnimal; i++){
        if(name.compare(animalList[i]->getName()) == 0){
            return animalList[i]; 
        }
    }
    return nullptr; //If can not find the animal with "animalName" then return nullptr
}

//Setter:
void  Player:: setName(string name){
    this->name = name; 
}
void Player:: setID(int ID){
    this->ID = ID; 
}

//Destructor:
Player:: ~Player(){
    for(int i = 0; i<maxAnimal; i++){
        delete animalList[i]; 
    }
    delete[] animalList; 
}