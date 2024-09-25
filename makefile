main: main.cpp AfricanElephant.cpp Animal.cpp BullDog.cpp Cactus.cpp ChessPiece.cpp Fortress.cpp GameProperty.cpp IndianElephant.cpp Mickey.cpp Player.cpp Poodle.cpp Rat.cpp Shepherd.cpp Sodier.cpp
	@g++ -std=c++17 main.cpp AfricanElephant.cpp Animal.cpp BullDog.cpp Cactus.cpp ChessPiece.cpp Fortress.cpp GameProperty.cpp IndianElephant.cpp Mickey.cpp Player.cpp Poodle.cpp Rat.cpp Shepherd.cpp Sodier.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

test: test.cpp
	@g++ -std=c++17 test.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o test -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./test

clear: 
	rm -f main