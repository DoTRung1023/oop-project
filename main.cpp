#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "GameProperty.h"
#include "ChessPiece.h"
#include "GameMove.h"

const char* imageFile[8] = {"./Assets/Pieces/rpoodle.png",
                            "./Assets/Pieces/rrat.png",
                            "./Assets/Pieces/rafrican.png",
                            "./Assets/Pieces/bpoodle.png",
                            "./Assets/Pieces/brat.png",
                            "./Assets/Pieces/bafrican.png",
                            "./Assets/Pieces/soldier.png",
                            "./Assets/Pieces/fortress.png"};

int main(){
    GameProperty newgame(700, 900, imageFile, "Animal Chess");
    newgame.run();

    return 0;
}

