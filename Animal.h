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
    Animal(string name); 
    Animal(); 
    virtual bool attack(int pieceID) = 0; 
    ~Animal(); 
};

#endif
