main: main.cpp Button.cpp GameIntro.cpp AfricanElephant.cpp Animal.cpp BullDog.cpp Cactus.cpp Character.cpp Fortress.cpp GameProperty.cpp IndianElephant.cpp Mickey.cpp Player.cpp Poodle.cpp Rat.cpp Shepherd.cpp Sodier.cpp GameMove.cpp Equipment.cpp Knife.cpp Hammer.cpp Arrow.cpp Armour.cpp RoundShield.cpp SpikeShield.cpp Weapon.cpp Shield.cpp
	@g++ -std=c++17 main.cpp Button.cpp GameIntro.cpp AfricanElephant.cpp Animal.cpp BullDog.cpp Cactus.cpp Character.cpp Fortress.cpp GameProperty.cpp IndianElephant.cpp Mickey.cpp Player.cpp Poodle.cpp Rat.cpp Shepherd.cpp Sodier.cpp GameMove.cpp Equipment.cpp Knife.cpp Hammer.cpp Arrow.cpp Armour.cpp RoundShield.cpp SpikeShield.cpp Weapon.cpp Shield.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

debug: main.cpp AfricanElephant.cpp Animal.cpp BullDog.cpp Cactus.cpp Character.cpp Fortress.cpp GameProperty.cpp IndianElephant.cpp Mickey.cpp Player.cpp Poodle.cpp Rat.cpp Shepherd.cpp Sodier.cpp GameMove.cpp Equipment.cpp Knife.cpp Hammer.cpp Arrow.cpp Armour.cpp RoundShield.cpp SpikeShield.cpp Weapon.cpp Shield.cpp
	@g++ -std=c++17 -Wall -Wextra -fsanitize=address main.cpp AfricanElephant.cpp Animal.cpp BullDog.cpp Cactus.cpp Character.cpp Fortress.cpp GameProperty.cpp IndianElephant.cpp Mickey.cpp Player.cpp Poodle.cpp Rat.cpp Shepherd.cpp Sodier.cpp GameMove.cpp Equipment.cpp Knife.cpp Hammer.cpp Arrow.cpp Armour.cpp RoundShield.cpp SpikeShield.cpp Weapon.cpp Shield.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main


test: test.cpp
	@g++ -std=c++17 test.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o test -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./test
	
clear: 
	@rm -f main debug


