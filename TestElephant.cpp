#include <iostream>
using namespace std; 
#include "TestElephant.h"
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

void TestElephant:: TestConstructor(){
    Elephant e1; 
    if(e1.getName().compare("")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    //Test setName(); 
    e1.setName("Elephant"); 
    if(e1.getName().compare("Mice")){
        cout << "setName() passed" << endl; 
    }
}
void TestElephant:: testAttack(){
    Elephant e2; 
    Dog* targetDog = new Dog();
    Mice* targetMice = new Mice();
    Elephant* targetElephant = new Elephant();

    if(e2.attack(targetDog) == true){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(e2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(e2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
}
void TestElephant:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Elephant()
}

void TestElephant::testColor(){
    Elephant e3;
    // test default color
    if(e3.getColor() == ""){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    e3.setColor("red");
    if(e3.getColor() == "red"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    e3.setColor("blue");
    if(e3.getColor() == "blue"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
}
