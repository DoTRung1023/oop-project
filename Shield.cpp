#include <iostream>
#include "Equipment.h"
#include "Shield.h"

using namespace std;

Shield::Shield(): Shield(0, "", 0, 0){}
Shield::Shield(int ID, string name, int damage, int defence): 
                Equipment(ID, name, "Shield", damage, defence){}
void Shield::showInfo(){
    cout << "Name: " << name << "\n";
    cout << "ID: " << ID << "\n";
    cout << "Damage: " << damage << "\n";
    cout << "Defence: " << defence << "\n";
}

