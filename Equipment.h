#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <string.h>

using namespace std;

class Equipment
{
private:
protected:
    int ID;
    string nameEquipment;
    string typeEquipment;
    int atk;
    int def;
public:
    Equipment();
    Equipment(int ID, string nameEquipment, string typeEquipment, int atk, int def);
    virtual void showInfo() = 0;
};

#endif