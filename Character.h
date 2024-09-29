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
    string name;
public:
    Character();
    Character(string name);
    string getName();
    void setName(string name);
    virtual ~Character(); 
};

#endif
