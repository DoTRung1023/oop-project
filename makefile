main: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp
	@g++ -std=c++17 main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

debug: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp
	@g++ -std=c++17 -Wall -Wextra -fsanitize=address main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Sodier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

clear: 
	@rm -f main debug

#For Unit test: 

testAnimal: TestSoldier.cpp TestFortress.cpp TestElephant.cpp TestMice.cpp TestDog.cpp Animal.cpp Character.cpp  Dog.cpp Mice.cpp Elephant.cpp Fortress.cpp Sodier.cpp mainTestAnimal.cpp
	@g++ -std=c++17 -Wall -Wextra -fsanitize=address TestSoldier.cpp TestFortress.cpp TestElephant.cpp TestMice.cpp TestDog.cpp Animal.cpp Character.cpp  Dog.cpp Mice.cpp Elephant.cpp Fortress.cpp Sodier.cpp mainTestAnimal.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o testAnimal -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./testAnimal

testPlayer: Animal.cpp Dog.cpp Mice.cpp Elephant.cpp Character.cpp Player.cpp TestPlayer.cpp mainTestPlayer.cpp
	@g++ -std=c++17 -Wall -Wextra -fsanitize=address  Animal.cpp Dog.cpp Mice.cpp Elephant.cpp Character.cpp Player.cpp TestPlayer.cpp mainTestPlayer.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o testAnimal -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
