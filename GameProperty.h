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
#include "Character.h"
#include "GameMove.h"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

struct Move{
    int old_X, old_Y, new_X, new_Y;
    Move(){}
    Move(int old_X, int old_Y, int new_X, int new_Y);
};

struct Board
{
    int index[7][9] = { {5, -1, 0, -1, -1, -1, 8, -1, 13},
                        {-1, 6, -1, -1, -1, -1, -1, 14, -1},
                        {16, -1, 3, -1, -1, -1, 11, -1, 16},
                        {17, 16, -1, -1, -1, -1, -1, 16, 17},
                        {16, -1, 1, -1, -1, -1, 9, -1, 16},
                        {-1, 7, -1, -1, -1, -1, -1, 15, -1},
                        {2, -1, 4, -1, -1, -1, 12, -1, 10}};
};

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
    Board board;
    Texture pieceTexture[18]; 
    int selectAxis[2];
    bool select = 0;
    int choose_X, choose_Y;
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