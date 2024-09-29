#include "GameIntro.h"
#include "GameProperty.h"
#include<iostream>

using namespace sf; 
using namespace std; 

//Game name
//Start button 
//Instruction button 
//Quit button

const char* imageFile[8] = {"./Assets/Pieces/rpoodle.png",
                            "./Assets/Pieces/rrat.png",
                            "./Assets/Pieces/rafrican.png",
                            "./Assets/Pieces/bpoodle.png",
                            "./Assets/Pieces/brat.png",
                            "./Assets/Pieces/bafrican.png",
                            "./Assets/Pieces/soldier.png",
                            "./Assets/Pieces/fortress.png"};

//float x, float y, float width, float height, string text, Font* font, Color idleColor, Color hoverColor, Color activeColor
GameIntro:: GameIntro(){
    //Create the window for the menu
    introWindow.create(VideoMode(700, 900), "Animal Chess"); 

    //Load the font;
    
    if (!font.loadFromFile("Assets/Font/Times New Normal Regular.ttf")) { // Make sure to specify the correct path
        cout << "Error loading font!" << endl;
        return;
    }


    //Create the title of the game:
    RectangleShape rectangle(Vector2f(400.0f, 100.0f)); // Width x Height
    rectangle.setFillColor(Color::White); // Set rectangle color
    rectangle.setPosition((introWindow.getSize().x / 2) - (rectangle.getSize().x / 2), 20.0f); // Center it at the top

    //Create Text object for the title:
    Text title;
    title.setFont(font);
    title.setString("Animal Chess"); // Set the title text
    title.setCharacterSize(36); // Set text size
    title.setFillColor(Color::Black); // Set text color

    // Center the text in the rectangle
    FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.width / 2, textRect.height / 2); // Set origin to center of text
    title.setPosition(rectangle.getPosition().x + rectangle.getSize().x / 2, 
                      rectangle.getPosition().y + rectangle.getSize().y / 2); // Center the text in the rectangle
    
    //Create the Texture object:
    Texture introImageTexture;

    //Load the logo texture into introImageTexture object:
    if(!introImageTexture.loadFromFile("Assets/IntroImages/AnimalChessProjectImage.jpg")){
        cerr << "Error loading logo!" << std::endl; //Print out announcement if can not find the photo
        return; 
    }

    //Create a sprite for the introInamge:
    Sprite introImageSprite;
    introImageSprite.setTexture(introImageTexture); 

    //Set the size of the image 

    //Make the introImage in the middle of the screen: 
    sf::Vector2u windowSize = introWindow.getSize();
    sf::Vector2u introSize = introImageTexture.getSize();
    
    float scaleX = static_cast<float>(windowSize.x) / introSize.x; // Divide the width of window by the width of introTexture to get the scale of width
    float scaleY = static_cast<float>(windowSize.y) / introSize.y; // Divide the width of window by the width of introTexture to get the scale of height

    introImageSprite.setScale(scaleX,scaleY); //Scale the sprite


    //Define 3 button in the intro menu: 
    Button startGameButton(windowSize.x/2 - 100, windowSize.y/2 - 100, 200.0, 50.0, "Start", &font,Color:: White, Color:: White, Color:: Blue);
    Button ruleInstructionButton(windowSize.x/2 - 100, windowSize.y/2 , 200.0, 50.0, "Instruction", &font,Color:: White, Color:: White, Color:: Blue); 
    Button quitButton(windowSize.x/2 - 100, windowSize.y/2 + 100, 200.0, 50.0, "Quit", &font,Color:: White, Color:: White, Color:: Blue); 


    // Main loop
    while (introWindow.isOpen()) {

        Vector2f mousePos = introWindow.mapPixelToCoords(sf::Mouse::getPosition(introWindow));

        // Update the button state based on mouse position
        startGameButton.update(mousePos);
        
        ruleInstructionButton.update(mousePos);

        quitButton.update(mousePos);

        Event event;
        while (introWindow.pollEvent(event)) {
            if (event.type == Event::Closed)
                introWindow.close();
            if(event.type == sf::Event::MouseButtonPressed){
                if(startGameButton.getButtonStates() == BTN_ACTIVE){
                    introWindow.close();
                    GameProperty newgame(700, 900, imageFile, "Animal Chess");
                    newgame.run(); 
                }
                else if(ruleInstructionButton.getButtonStates() == BTN_ACTIVE){
                    cout << "Instruction" << endl; 
                }
                else if(quitButton.getButtonStates() == BTN_ACTIVE){
                    introWindow.close(); 
                }
            }
        }
        // Clear the window
        introWindow.clear(sf::Color::Black);

        // Draw the IntroImage
        introWindow.draw(introImageSprite);

        //Draw the button
        startGameButton.render(&introWindow);
        ruleInstructionButton.render(&introWindow);
        quitButton.render(&introWindow);

        //Draw the rectangle and the title
        introWindow.draw(rectangle);
        introWindow.draw(title);

        // Display the contents of the window
        introWindow.display();
    }

}

void GameIntro:: closeWindow(){
    introWindow.close(); 
}




