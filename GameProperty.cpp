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
#include "Character.h"
#include "GameMove.h"

using namespace std;
using namespace sf;

GameProperty::GameProperty(int width, int height, const char* imageFile[18], string gameName){
    // colorsNeed for board
    colorsNeed[0].r = 181; // wood color
    colorsNeed[0].g = 123; 
    colorsNeed[0].b = 66;
    colorsNeed[1].r = 0; // black
    colorsNeed[1].g = 0;
    colorsNeed[1].b = 0;
    colorsNeed[2].r = 255; // olive green
    colorsNeed[2].g = 252;
    colorsNeed[2].b = 135;
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
    createPiece(imageFile); //Possible error here
    mapPieces();
    win.create(VideoMode(width, height), gameName);
}

void GameProperty::createPlayers(){
    // set red player property (player 1):
    players1 = new Player("red");
    // animal1
    redAnimals = players1->getAnimalList();
    
    // fortress1
    redFortress = players1->getFortress();
    // soldiers1
    redSoldiers = players1->getSoldierList();

    // set blue player property (Player 2):
    players2 = new Player("blue");
    // animals
    blueAnimals = players2->getAnimalList();

    // fortress
    blueFortress = players2->getFortress();
    // soldiers
    blueSoldiers = players2->getSoldierList();
}
void GameProperty::createPiece(const char* imageFile[18]){
    Board currentBoard = moveAnimal.getBoard();
    // load image to texture
    // IntRect blank;
    for(int i = 0; i<18; i++){
        // pieceTexture[i].loadFromFile(imageFile[i], blank);
        pieceTexture[i].loadFromFile(imageFile[i]);
    }
    // set texture to piece
    int index = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            pieces[index].pieceID = currentBoard.index[i][j];
            pieces[index].x = i;
            pieces[index].y = j;
            if(pieces[index].pieceID != -1){
                if(pieces[index].pieceID < 8){
                    pieces[index].character = redAnimals[pieces[index].pieceID];
                }
                else if(pieces[index].pieceID < 16){
                    pieces[index].character = blueAnimals[pieces[index].pieceID-8];
                }
                else if(pieces[index].pieceID == 17){
                    if(j < 4){
                        pieces[index].character = redFortress;
                    }
                    else{
                        pieces[index].character = blueFortress;
                    }
                }
                else{
                    if(j<4){
                        if(i == 2){
                            pieces[index].character = redSoldiers[0];  
                        }
                        else if(i == 3){
                            pieces[index].character = redSoldiers[1];  
                        }
                        else {
                            pieces[index].character = redSoldiers[2];  
                        }
                    }
                    else {
                        if(j<4){
                            if(i == 2){
                                pieces[index].character = blueSoldiers[0];  
                            }
                            else if(i == 3){
                                pieces[index].character = blueSoldiers[1];  
                            }
                            else {
                                pieces[index].character = blueSoldiers[2];  
                            }
                        }
                    }
                }
                pieces[index].image.setTexture(pieceTexture[pieces[index].pieceID], true);
                pieces[index].draw = 1;
            }
            else {
                pieces[index].character = nullptr;
            }
            index++;
        }
    }}

void GameProperty::drawSquares(){
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            win.draw(squares[i][j]);
        }
    }
}

void GameProperty::drawImage(){
    for(int i = 0; i<63; i++){
        if(pieces[i].draw == 1){
            win.draw(pieces[i].image);
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
        if(pieces[i].draw == 1){
            pieces[i].image.setPosition(sf::Vector2f(holder.left + (pieces[i].x * holder.width / 7), holder.top + (pieces[i].y * holder.height / 9)));
            pieces[i].image.setScale(holder.width / 1470.f, holder.height / 1890.f);
        }
    }
}

void GameProperty::mapPieces(Move moving){
    ChessPiece *current;
    for (int i = 0; i < 63; ++i){
        if (pieces[i].draw == 1){
            if (pieces[i].x == moving.old_X && pieces[i].y == moving.old_Y){
                current = &pieces[i];
            }
            if (pieces[i].x == moving.new_X && pieces[i].y == moving.new_Y){
                pieces[i].draw = 0;
            }
        }
    }
    current->x = moving.new_X;
    current->y = moving.new_Y;
    current->image.setPosition(sf::Vector2f(holder.left + (current->x * holder.width / 7), holder.top + (current->y * holder.height / 9)));
    current->image.setScale(holder.width / 1470.f, holder.height / 1890.f);
}


void GameProperty::run(){
    Board currentBoard = moveAnimal.getBoard();
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
            else if(event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Button::Left){
                    // get click position
                    int click_X, click_Y;
                    click_X = event.mouseButton.x;
                    click_Y = event.mouseButton.y;
                    // calculate click square
                    int square_X, square_Y;
                    square_X = ((click_X - holder.left) - ((click_X - holder.left) % (holder.width / 7))) / (holder.width / 7);
                    square_Y = ((click_Y - holder.top) - ((click_Y - holder.top) % (holder.height / 9))) / (holder.height / 9);
                    // not select -> highlight the selected square
                    if (select == 0){
                        if (click_X >= holder.left && click_X <= holder.left + holder.width && 
                            click_Y > holder.top && click_Y < holder.top + holder.height &&
                            currentBoard.index[selectAxis[0]][selectAxis[0]] != 16 &&
                            currentBoard.index[selectAxis[0]][selectAxis[0]] != 17){
                            selectAxis[0] = square_X;
                            selectAxis[1] = square_Y;
                            // highlight
                            squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[2]);
                            squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                            select = 1;
                        }
                    }
                    // already select
                    else{
                        // change color of selected square to original color
                        if (selectAxis[0] == square_X && selectAxis[1] == square_Y){
                            squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                            squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                            select = 0;
                        }
                        // move the chess to new position
                        else{
                            Move newMove(selectAxis[0], selectAxis[1], square_X, square_Y);
                            // if move is valid -> move
                            if(moveAnimal.playMove(newMove)){
                                mapPieces(newMove);
                                moveAnimal.nextTurn();
                            }
                            // turn the highlighted square back to original color
                            squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                            squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                            select = 0;
                        }
                    }
                }
                else if (event.mouseButton.button == sf::Mouse::Button::Right){
                    squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                    squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                    select = 0;
                }
            }
        }
        win.clear();
        drawSquares();
        drawImage();
        win.display();
    }
}

GameProperty:: ~GameProperty(){
    //Delete animal:
    for(int i = 0; i<8; i++){
        delete redAnimals[i];
        delete blueAnimals[i]; 
    }
    delete[] redAnimals; 
    delete[] blueAnimals; 

    //Delete soldier:
    for(int i = 0; i<3; i++){
        delete redSoldiers[i]; 
        delete blueSoldiers[i];
    }
    delete[] blueSoldiers; 
    delete[] redSoldiers; 
    delete blueFortress; 
    delete redFortress; 

}