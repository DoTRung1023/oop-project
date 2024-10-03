#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameMove.h"
#include "GameProperty.h"

using namespace std;

// get possible move and push in the vector
void GameMove::characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn){
    // true = red, false = blue
    bool validColor = currentBoard.index[current_X][current_Y] < 8;
    // check 4 direction to get possible move
    if (currentBoard.index[current_X][current_Y] > -1 && currentBoard.index[current_X][current_Y] < 16){
        if(current_X>0){
            possibleMoves.push_back(Move(current_X, current_Y, current_X-1, current_Y));
        }
        if(current_X<7){
            possibleMoves.push_back(Move(current_X, current_Y, current_X+1, current_Y));
        }
        if(current_Y>0){
            possibleMoves.push_back(Move(current_X, current_Y, current_X, current_Y-1));
        }
        if(current_Y<9){
            possibleMoves.push_back(Move(current_X, current_Y, current_X, current_Y+1));
        }
    }
}
// search all board to get possible move
vector<Move> GameMove::getLegalMoves(Board currentBoard, bool turn){
    vector<Move> possibleMoves;
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 9; ++j){
            if(currentBoard.index[i][j] > -1 && currentBoard.index[i][j] < 16){
                characterMove(possibleMoves, i, j, turn);
            }
        }
    }
    return possibleMoves;
}

bool GameMove::playMove(Move newMove, Character* aimPiece, Character* choosePiece){
    vector<Move> possibleMoves = getLegalMoves(currentBoard, turn);
    Move temp;
    for (int i = 0; i < possibleMoves.size(); i++){
        temp = possibleMoves[i];
        // if the move matches a possible move -> move
        if (temp.old_X == newMove.old_X && temp.old_Y == newMove.old_Y && temp.new_X == newMove.new_X && temp.new_Y == newMove.new_Y){
            if((choosePiece->attack(aimPiece) && choosePiece->color != aimPiece->color) || currentBoard.index[newMove.new_X][newMove.new_Y] == -1){
                if(choosePiece->attack(aimPiece)){
                    killMessage(aimPiece);
                }
                currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[newMove.old_X][newMove.old_Y];
                currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                return true;
            }
        }
    }
    wrongMoveMessage();
    return false;
}

void GameMove::killMessage(Character* killPiece){
    RenderWindow killWin(sf::VideoMode(500, 100), "SUCCESSFULL KILL");
    while(killWin.isOpen()){
        Event killEvent;
        while(killWin.pollEvent(killEvent)){
            if(killEvent.type == Event::Closed){
                killWin.close();
                break;
            }
        }
        Font font;
        Text text;
        killWin.clear(Color::White);
        string kill;
        kill = killPiece->color + " " + killPiece->getName() + " is killed!";
        text.setString(kill);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(30);
        // Center the text in warning
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(killWin.getSize().x / 2.0f,  // Center horizontally
                        killWin.getSize().y / 2.0f); // Center vertically
        killWin.draw(text);
        killWin.display();
    }
}
// message for wrong move
void GameMove::wrongMoveMessage(){
    RenderWindow wrongWin(sf::VideoMode(500, 100), "WRONG MOVE");
    while(wrongWin.isOpen()){
        Event wrongEvent;
        while(wrongWin.pollEvent(wrongEvent)){
            if(wrongEvent.type == Event::Closed){
                wrongWin.close();
                break;
            }
        }
        Font font;
        Text text;
        wrongWin.clear(Color::White);
        string msg = "Choose a valid move!";
        text.setString(msg);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(30);
        // Center the text in warning
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(wrongWin.getSize().x / 2.0f,  // Center horizontally
                        wrongWin.getSize().y / 2.0f); // Center vertically
        wrongWin.draw(text);
        wrongWin.display();
    }
}

// switch turn
bool GameMove::nextTurn(){
    turn = !turn;
    return turn;
}
// getter
bool GameMove::getTurn(){
    return turn;
}

Board* GameMove::getBoard(){
    return &currentBoard;
}
