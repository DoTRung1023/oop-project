#include <iostream>
using namespace std; 
#include "TestMice.h"
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

void TestMice:: TestConstructor(){
    Mice m1; 
    if(m1.getName().compare("")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    //Test setName(); 
    m1.setName("Mice"); 
    if(m1.getName().compare("Mice")){
        cout << "setName() passed" << endl; 
    }
}
void TestMice:: testAttack(){
    Mice m2; 
    Dog* targetDog = new Dog();
    Mice* targetMice = new Mice();
    Elephant* targetElephant = new Elephant();

    if(m2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(m2.attack(targetElephant) == true){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(m2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
}
void TestMice:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Dog()
}

