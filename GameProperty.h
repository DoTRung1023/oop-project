#ifndef __GAMEPROPERTY_H__
#define __GAMEPROPERTY_H__

#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "Player.h"
#include "Animal.h"
#include "Soldier.h"
#include "Fortress.h"
#include "Character.h"
#include "GameMove.h"
#include "Board.h"

using namespace std;
using namespace sf;

class GameProperty
{
private:
    sf::RenderWindow win;
    sf::RectangleShape squares[7][9];
    sf::IntRect holder;
    sf::Color colorsNeed[3];
    ChessPiece pieces[63];
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
    GameMove moveAnimal;
    Texture pieceTexture[8]; 
    int selectAxis[2];
    bool select = 0;
public:
    GameProperty(int width, int height, const char* imageFile[8], string gameName);
    void createPlayers();
    void createPiece(const char* imageFile[8]);
    void drawSquares();
    void drawImage();
    void setHolders();
    void mapPieces();
    void mapPieces(Move moving);
    void run();
    // void closeWindow(); 
    void displayTurn();
    void warning(int square_X, int square_Y);
    ~GameProperty(); 
};

#endif