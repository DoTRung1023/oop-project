#ifndef PLAYER_H
#define PLAYER_H
#include "Animal.h"


#include<iostream>
using namespace std; 

class Player{
    private:
        string name;
        int ID;
        int maxAnimal; 
        int currentAnimal;
        Animal** animalList; 
    public:
        Player(); //Constructor; 
        void addAnimal(Animal* animal); //Add an animal to the animalList; 
        void removeAnimal(int ID); //Remove an animal from the animalList; 

        //Getter:
        string getName(); 
        int getID(); 
        Animal** getAnimalList(); 

        //Setter:
        void setName(string name); 
        void setID(int ID);

};

#endif
