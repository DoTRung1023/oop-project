#ifndef TEST_PLAERY__H
#define TEST_PLAERY__H
#include "Animal.h"

class TestPlayer{
    public: 
        void runTestPlayer(){
            void TestConstructor(); 
            void TestGetAnimalList(); 
            void TestgetFortress(); 
            void TestGetSoldierList(); 
            void TestDestructor(); 
        }
    private: 
        void TestConstructor(); 
        void TestGetAnimalList(); 
        void TestgetFortress(); 
        void TestGetSoldierList(); 
        void TestDestructor(); 
};

#endif


// Player(); //Constructor; 
//         Animal** getAnimalList(); //Get the list of Animal
//         Fortress* getFortress(); //Get the fortress
//         Soldier** getSoldierList(); //Get the list of Soldier. 
//         ~Player(); //Destructor for delete the dynamic allocated memory. 