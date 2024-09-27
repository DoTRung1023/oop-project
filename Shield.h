#ifndef SHIELD_H
#define SHIELD_H

#include <iostream>
#include <string.h>
#include "Equipment.h"

using namespace std;

class Shield: public Equipment
{
public:
    Shield();
    Shield(string nameEquipment, int atk, int def);
};

#endif