#include <iostream>
#include "Equipment.h"

using namespace std;

Equipment::Equipment(): Equipment(0, "", "", 0, 0){}
Equipment::Equipment(int ID, string name, string type, int damage, int defence):
                    ID(ID), name(name), type(type), damage(damage), defence(defence){}


