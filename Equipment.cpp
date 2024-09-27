#include <iostream>
#include "Equipment.h"

using namespace std;

Equipment::Equipment(): Equipment("", "", 0, 0){}
Equipment::Equipment(string nameEquipment, string typeEquipment, int atk, int def): 
                                                                typeEquipment(typeEquipment), 
                                                                nameEquipment(nameEquipment), 
                                                                atk(atk), 
                                                                def(def){}

string Equipment::getName(){return nameEquipment;}
string Equipment::getType(){return typeEquipment;}
int Equipment::getAtk(){return atk;}
int Equipment::getDef(){return def;}


