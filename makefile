main: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp
	@g++ -std=c++17 main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main
	
clear: 
	@rm -f main debug


