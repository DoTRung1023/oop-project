#ifndef __GAMEPROPERTY_H__
#define __GAMEPROPERTY_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "Player.h"
#include "Animal.h"
#include "Soldier.h"
#include "Fortress.h"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class GameProperty
{
private:
    sf::RenderWindow win;
    sf::RectangleShape squares[7][9];
    sf::IntRect holder;
    sf::Color colorsNeed[2];
    ChessPiece** pieces;
    int width;
    int height;
    Player* players1;
    Player* players2;
    Animal** redAnimals;
    Animal** blueAnimals;
    Fortress* redFortress;
    Fortress* blueFortress;
    Soldier** redSoldiers;
    Soldier** blueSoldiers;
public:
    GameProperty(int width, int height, const char* imageFile[18], string gameName);
    void createPlayers();
    void createPiece(const char* imageFile[18]);
    void drawSquares();
    void drawImage();
    void setHolders();
    void mapPieces();
    void run();
};

#endif