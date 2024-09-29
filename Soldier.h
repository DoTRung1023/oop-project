#ifndef __SOLDIER_H__
#define __SOLDIER_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"

using namespace std;

class Soldier:public Character
{
public:
    Soldier();
    ~Soldier(); 
};

#endif