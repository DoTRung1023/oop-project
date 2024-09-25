#ifndef __SOLDIER_H__
#define __SOLDIER_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChessPiece.h"
using namespace std;

class Soldier:public ChessPiece
{
public:
    Soldier();
};

#endif