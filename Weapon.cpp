#include <iostream>
#include "Equipment.h"
#include "Weapon.h"

using namespace std;

Weapon::Weapon():Weapon("", 0, 0){}
Weapon::Weapon(string nameEquipment, int atk, int def):
                                            Equipment(nameEquipment, "Weapon", atk, def){}



