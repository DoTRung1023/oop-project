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
    string name;
    string type;
    int damage;
    int defence;
public:
    Equipment();
    Equipment(int ID, string name, string type, int damage, int defence);
    virtual void showInfo() = 0;
};

#endif