#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <string.h>

using namespace std;

class Equipment
{
private:
    string nameEquipment;
    string typeEquipment;
    int atk;
    int def;
public:
    Equipment();
    Equipment(string nameEquipment, string typeEquipment, int atk, int def);
    string getName();
    string getType();
    int getAtk();
    int getDef();
};

#endif