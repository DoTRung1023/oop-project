#ifndef __CHESSPIECE_H__
#define __CHESSPIECE_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ChessPiece
{
protected:
    string name;
    int atk;
    int hp;
    int def;
    int equipmentID = -1;
public:
    int pieceID = -1;
    int x, y;
    bool draw = 0;
    Sprite image;
    ChessPiece();
    ChessPiece(int atk, int hp, int def, string name, int pieceID);
    void setProperty(int pieceID, int x, int y);
    void setImage(const char* filePath);
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    void setEquipment(int equipmentID);
    string getEquipmentName(int weaponID);
};

#endif