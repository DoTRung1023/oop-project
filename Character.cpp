#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"

using namespace std;
using namespace sf;

Character::Character():Character(0, 0, 0, ""){}
Character::Character(int atk, int hp, int def, string name): atk(atk), hp(hp), def(def), name(name){}
void Character::setEquipment(int equipmentID){
    this->equipmentID = equipmentID;
}
string Character::getName(){
    return name;
}
void Character::setName(string name){
    this->name = name;
}
string Character::getEquipmentName(int weaponID){
    string result = ""; 
    switch(weaponID){
        case 1:
            result = "Staff"; 
            break;
        case 2:
            result = "Knife"; 
            break;
        case 3:
            result = "Hammer"; 
            break;
        case 4:
            result = "Arrow"; 
            break;
        case 5:
            result = "Armour"; 
            break;
        case 6:
            result = "Round Shield"; 
            break;
        case 7:
            result = "Spike Shield"; 
            break;
        case 8:
            result = "Heater Shield"; 
            break;
        default:
            result = "null"; 
            break;
    }   
    return result; 
}
Character::~Character(){

}