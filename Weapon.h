#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string.h>
#include "Equipment.h"

using namespace std;

class Weapon: public Equipment
{
public:
    Weapon();
    Weapon(string nameEquipment, int atk, int def);
};

#endif