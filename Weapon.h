#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string.h>
#include "Equipment.h"

using namespace std;

class Weapon: public Equipment
{
private:
protected:
    int range;
public:
    Weapon();
    Weapon(int ID, string name, int damage, int defence, int range);
    void showInfo();
};

#endif