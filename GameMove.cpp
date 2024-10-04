#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "GameMove.h"
#include "GameProperty.h"

using namespace std;

bool GameMove::turn = true; // red = true, blue = false;

// get possible move and push in the vector
void GameMove::characterMove(vector<Move> &possibleMoves, int current_X, int current_Y, bool turn){
    // true = red, false = blue
    bool validColor = currentBoard.index[current_X][current_Y] < 8;
    // check 4 direction to get possible move
    if (currentBoard.index[current_X][current_Y] > -1 && currentBoard.index[current_X][current_Y] < 16 && validColor == turn){
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
            if(choosePiece->attack(aimPiece) && choosePiece->color != aimPiece->color){
                killMessage(aimPiece);
                if(aimPiece->getName() == "fortress" || aimPiece->getName() == "soldier"){
                    currentBoard.index[newMove.new_X][newMove.new_Y] = -1;
                    currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                    disappear = true;
                    GameProperty::sounds[5].play();
                }
                else{
                    currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[newMove.old_X][newMove.old_Y];
                    currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                    disappear = false;
                    GameProperty::sounds[1].play();
                }
                return true;
            }
            else if(currentBoard.index[newMove.new_X][newMove.new_Y] == -1){
                currentBoard.index[newMove.new_X][newMove.new_Y] = currentBoard.index[newMove.old_X][newMove.old_Y];
                currentBoard.index[newMove.old_X][newMove.old_Y] = -1;
                disappear = false;
                GameProperty::sounds[0].play();
                return true;
            }
        }
    }
    wrongMoveMessage();
    disappear = false;
    return false;
}

void GameMove::killMessage(Character* killPiece){
    RenderWindow killWin(sf::VideoMode(410, 80), "SUCCESSFULL KILL");
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
    GameProperty::sounds[2].play();
    RenderWindow wrongWin(sf::VideoMode(380, 80), "WRONG MOVE");
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

void GameMove::saveTurn(){
    // The string to be written to the file
    std::string content = "red";

    if(turn == false){
        content = "blue";
    }

    // Create an output file stream
    std::ofstream file("./Assets/Text/turn.txt");

    // Write the string to the file
    file << content;

    // Close the file
    file.close();
    
}

void GameMove::loadTurn(){
    // Create an input file stream
    std::ifstream file("./Assets/Text/turn.txt");

    // Variable to hold the file content
    std::string fileContent;
    std::string line;

    // Read file line by line and append to fileContent
    while (std::getline(file, line)) {
        fileContent += line;  // Append line and newline
    }

    // Close the file
    file.close();

    if(fileContent == "red"){
        turn = true;
    }
    else{
        turn = false;
    }
}

void GameMove::resetTurn(){
    // The string to be written to the file
    std::string content = "red";

    // Create an output file stream
    std::ofstream file("./Assets/Text/turn.txt");

    // Write the string to the file
    file << content;

    // Close the file
    file.close();
}
