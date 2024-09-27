#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Equipment.h"
#include "Knife.h"
#include "Hammer.h"
#include "Arrow.h"
#include "Armour.h"
#include "RoundShield.h"
#include "SpikeShield.h"

using namespace std;
using namespace sf;

Character::Character():Character(0, 0, ""){}
Character::Character(int atk, int hp, string name): atk(atk), hp(hp), name(name){}

void Character::setEquipment(int weaponID){
    switch(weaponID){
        case 1:
            equipment = new Knife;
            break;
        case 2:
            equipment = new Hammer;
            break;
        case 3:
            equipment = new Arrow;
            break;
        case 4:
            equipment = new Armour;
            break;
        case 5:
            equipment = new RoundShield;
            break;
        case 6:
            equipment = new SpikeShield;
            break;
    }   
    atk += equipment->getAtk();
    hp += equipment->getDef();
}
Character::~Character(){

}