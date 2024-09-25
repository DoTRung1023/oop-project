#ifndef ANIMAL_H
#define ANIMAL_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "ChessPiece.h"

using namespace std; 
using namespace sf;

class Animal:public ChessPiece
{
public:
    Animal(int atk, int hp, int def, string name, int ID); 
    Animal(); 
    string getName() = 0;
    void setName(string name) = 0;
};

#endif
