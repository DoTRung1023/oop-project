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
    Mice m2; 
    // test different team
    m2.setColor("red");
    Character* targetDog = new Dog();
    targetDog->setColor("blue");
    Character* targetMice = new Mice();
    targetDog->setColor("blue");
    Character* targetElephant = new Elephant();
    targetDog->setColor("blue");
    Character* targetSoldier = new Soldier();
    targetDog->setColor("blue");
    Character* targetFortress = new Fortress();
    targetDog->setColor("blue");

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
    if(m2.attack(targetSoldier) == true){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(m2.attack(targetFortress) == true){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    // test same team
    m2.setColor("red");
    targetDog->setColor("red");
    targetDog->setColor("red");
    targetDog->setColor("red");
    targetDog->setColor("red");
    targetDog->setColor("red");

    if(m2.attack(targetDog) == false){
        cout << "attack to targetDog test Passed" << endl; 
    }
    else{
        cout << "attack to targetDog test Failed"<< endl; 
    }
    if(m2.attack(targetElephant) == false){
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
    if(m2.attack(targetSoldier) == false){
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    else{
        cout << "attack to targetSoldier test Passed"<< endl; 
    }
    if(m2.attack(targetFortress) == false){
        cout << "attack to targetFortress test Passed"<< endl; 
    }
    else{
        cout << "attack to targetFortress test Passed"<< endl; 
    }

    delete targetDog; 
    delete targetElephant;
    delete targetMice; 
    delete targetSoldier;
    delete targetFortress;
}
void TestSoldier:: testDestructor(){
    //Nothing to test as there is nothing in the implemetation of ~Soldier()
}

void TestSoldier::testColor(){
    Soldier s3;
    // test default color
    if(s3.getColor() == ""){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    s3.setColor("red");
    if(s3.getColor() == "red"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
    s3.setColor("blue");
    if(s3.getColor() == "blue"){
        cout << "getColor() passed" << endl;
    }
    else{
        cout << "getColor() failed" << endl;
    }
}
