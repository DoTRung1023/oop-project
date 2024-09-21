#ifndef PLAYER_H
#define PLAYER_H
#include "Animal.h"


#include<iostream>
using namespace std; 

class Player{
    private:
        int ID;
        int maxAnimal; 
        int currentAnimal;
        int removeIndex; 
        string name;
        Animal** animalList; 
        
    public:
        Player(); //Default Constructor; 
        Player(string name, int id); //Optional Constructor
        bool addAnimal(Animal* animal); //Add an animal to the animalList; 
        bool removeAnimal(string name); //Remove an animal from the animalList; 
        bool Player:: isInRemoveList(int index); //Check if "animal" is inside of animalList or not 


        //Getter:
        string getName(); 
        int getID(); 
        Animal** getAnimalList(); 
        Animal* getAnimal(string animalName); //Get a specific animal by name; 


        //Setter:
        void setName(string name); 
        void setID(int ID);

        //Destructor:
        ~Player(); 
};

#endif
