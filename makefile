main: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp 
	@g++ -std=c++17 main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

debug: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp 
	@g++ -std=c++17 -Wall -Wextra -fsanitize=address main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main


test: test.cpp
	@g++ -std=c++17 test.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o test -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./test
	
clear: 
	@rm -f main debug


