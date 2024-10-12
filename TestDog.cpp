#include <iostream>
#include "TestDog.h"

void TestDog:: TestConstructor(){
    Dog d1; 
    if(d1.getName().compare("")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    //Test setName(); 
    d1.setName("Dog"); 
    if(d1.getName().compare("Dog")){
        cout << "setName() passed" << endl; 
    }
}
void TestDog:: testAttack(){
    Dog d2; 
    Dog* targetDog = new Dog();
    Mice* targetMice = new Mice();
    Elephant* targetElephant = new Elephant();

    if(d2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(d2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(d2.attack(targetMice) == true){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
}
void TestDog:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Dog()
}

