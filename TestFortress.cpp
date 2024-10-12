#include <iostream>
#include "TestFortress.h"
#include "Character.h"
#include "Fortress.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

using namespace std; 

void TestFortress:: TestConstructor(){
    Fortress f1; 
    if(f1.getName().compare("")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    //Test setName(); 
    f1.setName("Fortress"); 
    if(f1.getName().compare("Fortress")){
        cout << "setName() passed" << endl; 
    }
}
void TestFortress:: testAttack(){
    Fortress f2; 
    Dog* targetDog = new Dog();
    Mice* targetMice = new Mice();
    Elephant* targetElephant = new Elephant();

    if(f2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(f2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(f2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
}
void TestFortress:: testDestructor(){

}