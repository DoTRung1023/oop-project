#include <iostream>
#include "Equipment.h"
#include "Shield.h"

using namespace std;

Shield::Shield():Shield("", 0, 0){}
Shield::Shield(string nameEquipment, int atk, int def):
                                                Equipment(nameEquipment, "Shield", atk, def){}
