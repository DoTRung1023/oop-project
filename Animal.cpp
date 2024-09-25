#include <iostream>
#include <string.h>
#include "Animal.h"
#include "ChessPiece.h"

//Optional Constructor
Animal::Animal(int atk, int hp, int def, string name, int ID):
                ChessPiece(atk, hp, def, name, ID){}

Animal:: Animal(): Animal(0, 0, 0, "", 0){}//Default Constructor
