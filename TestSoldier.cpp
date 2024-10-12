#include<iostream>
#include "TestSoldier.h"
#include "Character.h"
#include "Fortress.h"
#include "Soldier.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

using namespace std; 

void TestSoldier:: TestConstructor(){
    Soldier s1; 
    if(s1.getName().compare("")){
        cout << "getName() passed" << endl; 
    }
    else{
        cout << "getName() failed" << endl; 
    }
    //Test setName(); 
    s1.setName("Fortress"); 
    if(s1.getName().compare("Fortress")){
        cout << "setName() passed" << endl; 
    }
}
void TestSoldier:: testAttack(){
    Soldier s2; 
    Dog* targetDog = new Dog();
    Mice* targetMice = new Mice();
    Elephant* targetElephant = new Elephant();

    if(s2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(s2.attack(targetElephant) == false){
        cout << "attack to targetElephant test Passed"<< endl; 
    }
    else{
        cout << "attack to targetElephant test Failed"<< endl; 
    }
    if(s2.attack(targetMice) == false){
        cout << "attack to targetMice test Passed"<< endl; 
    }
    else{
        cout << "attack to targetMice test Passed"<< endl; 
    }
    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
}
void TestSoldier:: testDestructor(){

}