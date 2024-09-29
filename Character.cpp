#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"

using namespace std;
using namespace sf;

Character::Character():Character(""){}
Character::Character(string name):name(name){}

string Character::getName(){
    return name;
}
void Character::setName(string name){
    this->name = name;
}

Character::~Character(){

}