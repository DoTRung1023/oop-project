#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "GameProperty.h"
#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"
#include "BullDog.h"
#include "Poodle.h"
#include "Shepherd.h"
#include "Mickey.h"
#include "Rat.h"
#include "Cactus.h"
#include "IndianElephant.h"
#include "AfricanElephant.h"

using namespace std;
using namespace sf;

GameProperty::GameProperty(int width, int height, const char* imageFile[18], string gameName){
    pieces = new ChessPiece*[63];
    // colorsNeed for board
    colorsNeed[0].r = 181; // wood color
    colorsNeed[0].g = 123; 
    colorsNeed[0].b = 66;
    colorsNeed[1].r = 0; // black
    colorsNeed[1].g = 0;
    colorsNeed[1].b = 0;
    // fill colour for square
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            squares[i][j].setFillColor(colorsNeed[0]);
            squares[i][j].setOutlineColor(colorsNeed[1]);
        }
    }
    // define holder scale
    holder.left = 0;
    holder.top = 0;
    holder.width = width;
    holder.height = height;
    this->width = width;
    this->height = height;
    setHolders();
    createPlayers();
    createPiece(imageFile);
    mapPieces();
    win.create(VideoMode(width, height), gameName);
}

void GameProperty::createPlayers(){
    int index = 0;
    // set player 1
    players1 = new Player("red");
    // animal
    redAnimals = players1->getAnimalList();
    redAnimals[0] = new BullDog;
    redAnimals[1] = new Poodle;
    redAnimals[2] = new Shepherd;
    redAnimals[3] = new Mickey;
    redAnimals[4] = new Rat;
    redAnimals[5] = new Cactus;
    redAnimals[6] = new IndianElephant;
    redAnimals[7] = new AfricanElephant;
    for(int i = 0; i<8; i++){
        pieces[index] = redAnimals[i];
        pieces[index]->pieceID = i;
        index++;
    }
    // fortress
    redFortress = players1->getFortress();
    pieces[index] = redFortress;
    index++;
    // soldiers
    redSoldiers = players1->getSoldierList();
    for(int i = 0; i<3; i++){
        pieces[index] = redSoldiers[i];
        index++;
    }
    // set blue player property
    players2 = new Player("blue");
    // animals
    Animal** blueAnimals = players2->getAnimalList();
    blueAnimals[0] = new BullDog;
    blueAnimals[1] = new Poodle;
    blueAnimals[2] = new Shepherd;
    blueAnimals[3] = new Mickey;
    blueAnimals[4] = new Rat;
    blueAnimals[5] = new Cactus;
    blueAnimals[6] = new IndianElephant;
    blueAnimals[7] = new AfricanElephant;
    for(int i = 0; i<8; i++){
        pieces[index] = blueAnimals[i];
        pieces[index]->pieceID = i+8;
        index++;
    }
    // fortress
    blueFortress = players2->getFortress();
    pieces[index] = blueFortress;
    index++;
    // soldiers
    blueSoldiers = players2->getSoldierList();
    for(int i = 0; i<3; i++){
        pieces[index] = blueSoldiers[i];
        index++;
    }
}
void GameProperty::createPiece(const char* imageFile[18]){
    int index = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            pieces[index]->x = i;
            pieces[index]->y = j;
            if(pieces[index]->pieceID != -1){
                pieces[index]->setImage(imageFile[pieces[index]->pieceID]);
                pieces[index]->draw = 1;
            }
            index++;
        }
    }
}

void GameProperty::drawSquares(){
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            win.draw(squares[i][j]);
        }
    }
}

void GameProperty::drawImage(){
    for(int i = 0; i<63; i++){
        if(pieces[i]->draw == 1){
            win.draw(pieces[i]->image);
        }
    }
}
void GameProperty::setHolders(){
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            squares[i][j].setPosition(Vector2f(holder.left + (i * holder.width / 7), holder.top + (j * holder.height / 9)));
            squares[i][j].setSize(Vector2f(holder.width/7, holder.height/9));
            squares[i][j].setOutlineThickness(4);
        }
    }
}

void GameProperty::mapPieces(){
    for(int i = 0; i<63; i++){
        if(pieces[i]->draw == 1){
            pieces[i]->image.setPosition(sf::Vector2f(holder.left + (pieces[i]->x * holder.width / 7), holder.top + (pieces[i]->y * holder.height / 9)));
            pieces[i]->image.setScale(holder.width / 1470.f, holder.height / 1890.f);
        }
    }
}

void GameProperty::run(){
    while(win.isOpen()){
        Event event;
        while(win.pollEvent(event)){
            if(event.type == Event::Closed){
                win.close();
            }
            else if(event.type == Event::Resized){
                width = win.getSize().x;
                height = win.getSize().y;
                win.setView(View(FloatRect(0, 0, width, height)));
                if(width > height){
                    holder.height = height;
                    holder.width = height;
                    holder.left = (width-height)/2;
                    holder.top = 0;
                }
                else{
                    holder.height = width;
                    holder.width = width;
                    holder.top = (height-width)/2;
                    holder.left = 0;
                }
                setHolders();
                mapPieces();
            }
        }
        win.clear();
        drawSquares();
        drawImage();
        win.display();
    }
}