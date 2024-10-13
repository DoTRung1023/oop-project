#include<iostream>
#include "TestPlayer.h"
#include "Player.h"
#include "Character.h"
#include



void TestPlayer::  TestConstructor(){
    Player player1; 
    Animal** animalList = player1.getAnimalList();
    for(int i = 0; i<8; i++){
        cout << animalList[i]->getColor(); 
        cout << animalList[i]->getName(); 
    }

}
void TestPlayer:: TestGetAnimalList(){

}
void TestPlayer:: TestgetFortress(){

}
void TestPlayer:: TestGetSoldierList(){

}
void TestPlayer:: TestDestructor(){

}