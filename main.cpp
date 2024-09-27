#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "GameProperty.h"
#include "ChessPiece.h"
#include "GameMove.h"

const char* imageFile[18] = {"./Assets/Pieces/rbulldog.png",
                            "./Assets/Pieces/rpoodle.png",
                            "./Assets/Pieces/rshepherd.png",
                            "./Assets/Pieces/rmickey.png",
                            "./Assets/Pieces/rrat.png",
                            "./Assets/Pieces/rcactus.png",
                            "./Assets/Pieces/rindian.png",
                            "./Assets/Pieces/rafrican.png",
                            "./Assets/Pieces/bbulldog.png",
                            "./Assets/Pieces/bpoodle.png",
                            "./Assets/Pieces/bshepherd.png",
                            "./Assets/Pieces/bmickey.png",
                            "./Assets/Pieces/brat.png",
                            "./Assets/Pieces/bcactus.png",
                            "./Assets/Pieces/bindian.png",
                            "./Assets/Pieces/bafrican.png",
                            "./Assets/Pieces/soldier.png",
                            "./Assets/Pieces/fortress.png"};

int main(){
    GameProperty newgame(700, 900, imageFile, "Animal Chess");
    newgame.run();

    return 0;
}

