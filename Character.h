// parent class for all characters on the game board

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
    string name; // name of the character
public:
    string color = ""; // color of the character to know the side it is
    Character(); // default constructor
    Character(string name); // constructor
    // getter
    string getName(); 
    // setter
    void setName(string name);
    // virtual function attack to know if the aim piece on the board
    // is eligible or not
    virtual bool attack(Character* aimPiece);
    // destructor
    virtual ~Character(); 
};

#endif
