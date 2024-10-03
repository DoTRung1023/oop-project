#ifndef GAME_INTRO_H
#define GAME_INTRO_H
#include<iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf; 
using namespace std; 

class GameIntro{
    private:
        RenderWindow introWindow; //Object for the intro window
        // Texture introImageTexture; // Load the intro image into GPU 
        // Sprite introImageSprite; //An object for displaying the logo image
        // Vector2f windowSize; //Get the intro window size
        // Vector2f logoSize; //Get the intro logo size
        Font font; 
    public:
        GameIntro(); //Constructor for the Intro. 
        void closeWindow();  //Getter for introWindow. 
        void openRuleWindow(Font font); 
}; 

#endif