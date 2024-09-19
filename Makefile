main: main.cpp Equipment.cpp Weapon.cpp Shield.cpp Staff.cpp Knife.cpp Hammer.cpp Arrow.cpp Armour.cpp RoundShield.cpp SpikeShield.cpp HeaterShield.cpp
	@g++ -std=c++11 main.cpp Equipment.cpp Weapon.cpp Shield.cpp Staff.cpp Knife.cpp Hammer.cpp Arrow.cpp Armour.cpp RoundShield.cpp SpikeShield.cpp HeaterShield.cpp -o main
	@./main

clear:
	@rm -f main

# clean: 
# 	@rm main
