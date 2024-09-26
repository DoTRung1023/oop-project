#include <iostream>
#include <string.h>
#include "Animal.h"
#include "Character.h"

//Optional Constructor
Animal::Animal(int atk, int hp, int def, string name):
                Character(atk, hp, def, name){}

Animal:: Animal(): Animal(0, 0, 0, ""){}//Default Constructor

Animal:: ~Animal(){}