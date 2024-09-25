#ifndef SHIELD_H
#define SHIELD_H

#include <iostream>
#include <string.h>
#include "Equipment.h"

using namespace std;

class Shield: public Equipment
{
private:
protected:
public:
    Shield();
    Shield(int ID, string name, int damage, int defence);
    void showInfo();
};

#endif