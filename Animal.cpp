#include <iostream>
#include <string.h>
#include "Animal.h"
#include "Character.h"

//Optional Constructor
Animal::Animal(int atk, int hp, string name):
                Character(atk, hp, name){}

Animal:: Animal(): Animal(0, 0, ""){}//Default Constructor

Animal:: ~Animal(){}