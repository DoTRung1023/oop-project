#ifndef __GAMEPROPERTY_H__
#define __GAMEPROPERTY_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

struct ChessPiece
{
    sf::Sprite image;
    int pieceID, x, y;
    bool draw = 0;
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
    sf::Color colorsNeed[2];
    sf::Texture pieceTexture[18];
    ChessPiece pieces[63];
    Board boardIndex;
    int width;
    int height;
public:
    GameProperty(int width, int height, const char *imageFile[18], string name);
    void drawSquares();
    void drawImage();
    void setHolders();
    void mapPieces();
    void run();
};

#endif