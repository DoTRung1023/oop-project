#include <iostream>
#include "Equipment.h"

using namespace std;

Equipment::Equipment(): Equipment(0, "", "", 0, 0){}
Equipment::Equipment(int ID, string name, string type, int damage, int defence):
                    ID(ID), nameEquipment(name), typeEquipment(type), atk(damage), def(defence){}


