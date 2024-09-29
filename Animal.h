#ifndef ANIMAL_H
#define ANIMAL_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Character.h"

using namespace std; 
using namespace sf;

class Animal:public Character
{
public:
    Animal(int atk, int hp, string name); 
    Animal(); 
    string getName() = 0;
    void setName(string name) = 0;
    int getAtk() = 0;
    void setAtk(int atk) = 0;
    int getHp() = 0;
    void setHp(int hp) = 0;
    ~Animal(); 
};

#endif
