#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChessPiece.h"

using namespace std;
using namespace sf;

ChessPiece::ChessPiece():ChessPiece(0, 0, 0, "", 0){}
ChessPiece::ChessPiece(int atk, int hp, int def, string name, int pieceID): atk(atk), hp(hp), def(def), name(name), pieceID(pieceID){}
void ChessPiece::setProperty(int pieceID, int x, int y){
    this->pieceID = pieceID;
    this->x = x;
    this->y = y;
}
void ChessPiece::setImage(const char* filePath){
    Texture pieceTex;
    IntRect blank;
    pieceTex.loadFromFile(filePath, blank);
    image.setTexture(pieceTex, true);
}
void ChessPiece::setEquipment(int equipmentID){
    this->equipmentID = equipmentID;
}
string ChessPiece::getEquipmentName(int weaponID){
    string result = ""; 
    switch(weaponID){
        case 1:
            result = "Staff"; 
            break;
        case 2:
            result = "Knife"; 
            break;
        case 3:
            result = "Hammer"; 
            break;
        case 4:
            result = "Arrow"; 
            break;
        case 5:
            result = "Armour"; 
            break;
        case 6:
            result = "Round Shield"; 
            break;
        case 7:
            result = "Spike Shield"; 
            break;
        case 8:
            result = "Heater Shield"; 
            break;
        default:
            result = "null"; 
            break;
    }   
    return result; 
}
