#include "Button.h"

Button:: Button(float x, float y, float width, float height, string text, Font* font, Color idleColor,Color hoverColor,Color activeColor){
    this->shape.setPosition(Vector2f(x,y)); 
    this->shape.setSize(Vector2f(width, height)); 
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(Color::Black);  
    this->text.setCharacterSize(20); 

    this->text.setPosition(
    this->shape.getPosition().x + (this->shape.getSize().x / 2.f) - (this->text.getGlobalBounds().width / 2.f), 
    this->shape.getPosition().y + (this->shape.getSize().y / 2.f) - (this->text.getGlobalBounds().height / 2.f));    //Set the text position to be in the middle of the button 

    this->idleColor = idleColor; 
    this->hoverColor = hoverColor; 
    this->activeColor = activeColor; 

    this->shape.setFillColor(this->idleColor); 
}
Button:: ~Button(){

}

void Button:: render(RenderTarget* target){
    target->draw(this->shape); 
    target->draw(this->text); 
}



void Button:: update(const Vector2f mousePos){
      // Reset button state to idle
    this->buttonState = BTN_IDLE;

    // Hover state
    if (this->shape.getGlobalBounds().contains(mousePos)) {
        this->buttonState = BTN_HOVER;

        // Pressed state
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = BTN_ACTIVE;
        }
    }

    // Change button color based on state
    switch (this->buttonState) {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);             
            break;
    }
}

ButtonStates Button:: getButtonStates(){
    return this->buttonState; 
}