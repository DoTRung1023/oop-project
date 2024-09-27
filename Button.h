#ifndef BUTTON_H
#define BUTTON_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std; 
using namespace sf; 

enum ButtonStates { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE }; //Data member for the state of the button 

class Button{
    private:
        RectangleShape shape;
        Font* font; 
        Text text; 
        Color idleColor; 
        Color hoverColor; 
        Color activeColor;
        ButtonStates buttonState;
        
    public:
        Button(float x, float y, float width, float height, string text, Font* font, Color idleColor, Color hoverColor, Color activeColor); 
        ~Button(); 

        //Function:
        void render(RenderTarget* target);  
        void update(Vector2f mousePos);
        ButtonStates getButtonStates(); 

};

#endif