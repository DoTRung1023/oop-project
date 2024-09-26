#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "GameProperty.h"
#include "ChessPiece.h"

const char* imageFile[18] = {"./Assets/Pieces/Default/rbulldog.png",
                            "./Assets/Pieces/Default/rpoodle.png",
                            "./Assets/Pieces/Default/rshepherd.png",
                            "./Assets/Pieces/Default/rmickey.png",
                            "./Assets/Pieces/Default/rrat.png",
                            "./Assets/Pieces/Default/rcactus.png",
                            "./Assets/Pieces/Default/rindian.png",
                            "./Assets/Pieces/Default/rafrican.png",
                            "./Assets/Pieces/Default/bbulldog.png",
                            "./Assets/Pieces/Default/bpoodle.png",
                            "./Assets/Pieces/Default/bshepherd.png",
                            "./Assets/Pieces/Default/bmickey.png",
                            "./Assets/Pieces/Default/brat.png",
                            "./Assets/Pieces/Default/bcactus.png",
                            "./Assets/Pieces/Default/bindian.png",
                            "./Assets/Pieces/Default/bafrican.png",
                            "./Assets/Pieces/Default/soldier.png",
                            "./Assets/Pieces/Default/fortress.png"};

int main(){
    GameProperty newgame(700, 900, imageFile, "Animal Chess");
    newgame.run();

    return 0;
}

