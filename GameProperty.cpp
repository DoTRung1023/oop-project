#include <iostream>
#include <fstream>
#include <string>
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
#include "Dog.h"
#include "Elephant.h"
#include "Mice.h"
#include "Character.h"
#include "GameMove.h"
#include "GameIntro.h"
#include "Button.h"
#include "Board.h"

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
    players1 = new Player;
    // animal1
    redAnimals = players1->getAnimalList();
    
    // fortress1
    redFortress = players1->getFortress();
    // soldiers1
    redSoldiers = players1->getSoldierList();

    // set blue player property (Player 2):
    players2 = new Player;
    // animals
    blueAnimals = players2->getAnimalList();

    // fortress
    blueFortress = players2->getFortress();
    // soldiers
    blueSoldiers = players2->getSoldierList();
}
void GameProperty::createPiece(const char* imageFile[8]){
    // Board* currentBoard = moveAnimal.getBoard();

    // load image to texture
    // IntRect blank;
    for(int i = 0; i<8; i++){
        // pieceTexture[i].loadFromFile(imageFile[i], blank);
        pieceTexture[i].loadFromFile(imageFile[i]);
    }
    // set texture to piece
    int index = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            // get piece ID 
            pieces[index].pieceID = Board::index[i][j];
            pieces[index].x = i;
            pieces[index].y = j;
            // assign character to piece
            if(pieces[index].pieceID != -1){
                int insert = -1;
                if(pieces[index].pieceID < 8){
                    pieces[index].character = redAnimals[pieces[index].pieceID];
                    pieces[index].character->color = "red";
                }
                else if(pieces[index].pieceID < 16){
                    pieces[index].character = blueAnimals[pieces[index].pieceID-8];
                    pieces[index].character->color = "blue";
                }
                else if(pieces[index].pieceID == 22){
                    pieces[index].character = redFortress;
                    pieces[index].character->color = "red";
                    insert = 7;
                }
                else if(pieces[index].pieceID == 23){
                    pieces[index].character = blueFortress;
                    pieces[index].character->color = "blue";
                    insert = 7;
                }
                else if(pieces[index].pieceID == 16){
                    pieces[index].character = redSoldiers[0];
                    pieces[index].character->color = "red";
                    insert = 6;
                }
                else if(pieces[index].pieceID == 17){
                    pieces[index].character = redSoldiers[1];
                    pieces[index].character->color = "red";
                    insert = 6;
                }
                else if(pieces[index].pieceID == 18){
                    pieces[index].character = redSoldiers[2];
                    pieces[index].character->color = "red";
                    insert = 6;
                }
                else if(pieces[index].pieceID == 19){
                    pieces[index].character = blueSoldiers[0];
                    pieces[index].character->color = "blue";
                    insert = 6;
                }
                else if(pieces[index].pieceID == 20){
                    pieces[index].character = blueSoldiers[1];
                    pieces[index].character->color = "blue";
                    insert = 6;
                }
                else if(pieces[index].pieceID == 21){
                    pieces[index].character = blueSoldiers[2];
                    pieces[index].character->color = "blue";
                    insert = 6;
                }
                if(insert == -1){
                    if(pieces[index].character->getName() == "dog"){
                        insert = 0;
                    }
                    else if(pieces[index].character->getName() == "mice"){
                        insert = 1;
                    }
                    else if(pieces[index].character->getName() == "elephant"){
                        insert = 2;
                    }
                    if(pieces[index].character->color == "blue"){
                        insert += 3;
                    }
                }
                pieces[index].image.setTexture(pieceTexture[insert], true);  
                pieces[index].draw = 1;
            }
            else {
                pieces[index].character = nullptr;
            }
            index++;
        }
    }
}

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
    // Board* currentBoard = moveAnimal.getBoard();
    while(win.isOpen()){
        Event event;
        while(win.pollEvent(event)){
            // close main window
            if(event.type == Event::Closed){
                win.close();
                break;
            }
            // resize window
            else if(event.type == Event::Resized){
                width = win.getSize().x;
                height = win.getSize().y;
                win.setView(View(FloatRect(0, 0, width, height)));
                // calculate to keep game window ratio
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
            // mouse click event
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
                    bool turn  = moveAnimal.getTurn();
                    if (select == 0){
                        if (click_X >= holder.left && click_X <= holder.left + holder.width && 
                            click_Y > holder.top && click_Y < holder.top + holder.height){
                            // currentBoard = moveAnimal.getBoard();
                            // warning if choose a wrong square
                            if(!((Board::index[square_X][square_Y] >= 0 && 
                                Board::index[square_X][square_Y] <= 7 &&
                                turn == true) || 
                                (Board::index[square_X][square_Y] >= 8 && 
                                Board::index[square_X][square_Y] <= 15 &&
                                turn == false))){
                                    warning();
                            }
                            // store selected square axes
                            else{
                                selectAxis[0] = square_X;
                                selectAxis[1] = square_Y;
                                // highlight
                                squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[2]);
                                squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                                select = 1;
                            }
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
                            // currentBoard = moveAnimal.getBoard();
                            Character* aimPiece;
                            Character* choosePiece;
                            int aimID;
                            int chooseID;
                            for(int i = 0; i<63; i++){
                                if(pieces[i].pieceID == Board::index[square_X][square_Y]){
                                    aimPiece = pieces[i].character;
                                    aimID = i;
                                }
                                if(pieces[i].pieceID == Board::index[selectAxis[0]][selectAxis[1]]){
                                    choosePiece = pieces[i].character;
                                    chooseID = i;
                                }
                            }
                            if(moveAnimal.playMove(newMove, aimPiece, choosePiece)){
                                mapPieces(newMove);
                                moveAnimal.nextTurn();
                                if(moveAnimal.disappear == true){
                                    pieces[aimID].draw = 0;
                                    pieces[chooseID].draw = 0;
                                }
                                if(checkWinner() != winner){
                                    winner = checkWinner();
                                    squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                                    squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                                    select = 0;
                                    win.clear();
                                    drawSquares();
                                    drawImage();
                                    win.display();
                                    showWinner();
                                    win.close();
                                    break;
                                }
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
            // help window
            else if(event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::H){
                    helpWindow();
                    // RenderWindow helpWin(sf::VideoMode(500, 100), "HELP");
                    // while(helpWin.isOpen()){
                    //     Event helpEvent;
                    //     while(helpWin.pollEvent(helpEvent)){
                    //         if(helpEvent.type == Event::Closed){
                    //             helpWin.close();
                    //             break;
                    //         }
                    //     }
                    // }
                }
            }
        }
        win.clear();
        drawSquares();
        drawImage();
        displayTurn();
        win.display();
    }
    GameIntro newGame; 
}
void GameProperty::displayTurn(){
    bool turn  = moveAnimal.getTurn();
    std::string msg = "BLUE";
    if(turn == true){
        msg = "RED";
    }
    Text info;
    Font font;
    font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
    info.setFont(font);
    info.setString(msg);
    info.setCharacterSize(100);
    info.setFillColor(sf::Color(255, 255, 255, 100));
    // Get the bounds of the text to center it
    sf::FloatRect textBounds = info.getGlobalBounds();
    // Calculate the position to center the text
    float xPosition = (win.getSize().x / 2) - (textBounds.width / 2);
    float yPosition = (win.getSize().y / 2) - (textBounds.height / 2);
    info.setPosition(xPosition, yPosition);
    win.draw(info);
}

void GameProperty::warning(){
    RenderWindow warningWin(sf::VideoMode(500, 100), "WARNING");
    while(warningWin.isOpen()){
        Event warningEvent;
        while(warningWin.pollEvent(warningEvent)){
            if(warningEvent.type == Event::Closed){
                warningWin.close();
                break;
            }
        }
        Font font;
        Text text;
        warningWin.clear(Color::White);
        string warning;
        warning = "You chose a valid animal!";
        text.setString(warning);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(30);
        // Center the text in warning
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(warningWin.getSize().x / 2.0f,  // Center horizontally
                        warningWin.getSize().y / 2.0f); // Center vertically
        warningWin.draw(text);
        warningWin.display();
    }
}

string GameProperty::checkWinner(){
    // Board* currentBoard = moveAnimal.getBoard();
    // check red fortress
    if(Board::index[3][0] != 22){
        reason = 1;
        return "blue";
    }
    // check blue fortress
    else if(Board::index[3][8] != 23){
        reason = 1;
        return "red";
    }
    // check red animals
    int countRed = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            if(Board::index[i][j] > -1 && Board::index[i][j] < 8){
                countRed++;
                break;
            }
        }
    }
    // check blue animals
    int countBlue = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            if(Board::index[i][j] >= 8 && Board::index[i][j] <= 15){
                countBlue++;
                break;
            }
        }
    }
    if(countBlue == 0){
        reason = 2;
        return "blue";
    }
    else if(countRed == 0){
        reason = 2;
        return "red";
    }
    return " ";
}

void GameProperty::showWinner(){
    std::ifstream file;
    // load reason
    if(reason == 1){
        // open the file
        file.open("./Assets/Text/reason1.txt");
    }
    else if(reason == 2){
        // open the file
        file.open("./Assets/Text/reason2.txt");
    }
    // String to store the file content
    std::string fileContent;
    std::string line;
    // Read the file line by line and append to the string
    while (std::getline(file, line)) {
        fileContent += line + "\n";  // Add each line followed by a newline
    }
    // Close the file when done
    file.close();
    RenderWindow winnerWin(sf::VideoMode(730, 80), "WINNER");
    while(winnerWin.isOpen()){
        Event winnerEvent;
        while(winnerWin.pollEvent(winnerEvent)){
            if(winnerEvent.type == Event::Closed){
                winnerWin.close();
                break;
            }
        }
        Font font;
        Text text;
        winnerWin.clear(Color::White);
        string msg = winner + line;
        text.setString(msg);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(30);
        // Center the text in warning
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(winnerWin.getSize().x / 2.0f,  // Center horizontally
                        winnerWin.getSize().y / 2.0f); // Center vertically
        winnerWin.draw(text);
        winnerWin.display();
    }
}

void GameProperty::helpWindow(){
    RenderWindow helpWin(sf::VideoMode(500, 650), "HELP");
    Font font;
    //Load the font;
    if (!font.loadFromFile("Assets/Font/Times New Normal Regular.ttf")) { // Make sure to specify the correct path
        cout << "Error loading font!" << endl;
        return;
    }

    //Create the title of the game:
    RectangleShape rectangle(Vector2f(400.0f, 100.0f)); // Width x Height
    rectangle.setFillColor(Color::White); // Set rectangle color
    rectangle.setPosition((helpWin.getSize().x / 2) - (rectangle.getSize().x / 2), 20.0f); // Center it at the top

    //Create Text object for the title:
    Text title;
    title.setFont(font);
    title.setString("Help"); // Set the title text
    title.setCharacterSize(36); // Set text size
    title.setFillColor(Color::Black); // Set text color

    // Center the text in the rectangle
    FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.width / 2, textRect.height / 2); // Set origin to center of text
    title.setPosition(rectangle.getPosition().x + rectangle.getSize().x / 2, 
                      rectangle.getPosition().y + rectangle.getSize().y / 2); // Center the text in the rectangle
    
    sf::Vector2u windowSize = helpWin.getSize();

    //Define 4 button in the intro menu: 
    Button restartGameButton(windowSize.x/2 - 100, windowSize.y/2 - 100, 200.0, 50.0, "Restart", &font,Color:: White, Color:: White, Color:: Blue);
    Button ruleInstructionButton(windowSize.x/2 - 100, windowSize.y/2, 200.0, 50.0, "Instruction", &font,Color:: White, Color:: White, Color:: Blue);
    Button saveGameButton(windowSize.x/2 - 100, windowSize.y/2 + 100 , 200.0, 50.0, "Save & Quit", &font,Color:: White, Color:: White, Color:: Blue); 
    Button quitButton(windowSize.x/2 - 100, windowSize.y/2 + 200, 200.0, 50.0, "Quit without save", &font,Color:: White, Color:: White, Color:: Blue); 


    // Main loop
    while (helpWin.isOpen()) {

        Vector2f mousePos = helpWin.mapPixelToCoords(sf::Mouse::getPosition(helpWin));

        // Update the button state based on mouse position
        restartGameButton.update(mousePos);
        
        ruleInstructionButton.update(mousePos);

        saveGameButton.update(mousePos);

        quitButton.update(mousePos);

        Event event;
        while (helpWin.pollEvent(event)) {
            if (event.type == Event::Closed){
                helpWin.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                if(restartGameButton.getButtonStates() == BTN_ACTIVE){
                }
                else if(ruleInstructionButton.getButtonStates() == BTN_ACTIVE){
                }
                else if(saveGameButton.getButtonStates() == BTN_ACTIVE){
                }
                else if(quitButton.getButtonStates() == BTN_ACTIVE){
                }
            }
        }
        // Clear the window
        helpWin.clear(sf::Color::White);

        //Draw the button
        restartGameButton.render(&helpWin);
        ruleInstructionButton.render(&helpWin);
        saveGameButton.render(&helpWin); 
        quitButton.render(&helpWin);
        

        //Draw the rectangle and the title
        helpWin.draw(rectangle);
        helpWin.draw(title);

        // Display the contents of the window
        helpWin.display();
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