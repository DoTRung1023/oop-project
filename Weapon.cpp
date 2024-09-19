#include <iostream>
#include "Equipment.h"
#include "Weapon.h"

using namespace std;

Weapon::Weapon(): Weapon(0, "", 0, 0, 0){}
Weapon::Weapon(int ID, string name, int damage, int defence, int range): 
                Equipment(ID, name, "Weapon", damage, defence), range(range){}
void Weapon::showInfo(){
    cout << "Name: " << name << "\n";
    cout << "ID: " << ID << "\n";
    cout << "Damage: " << damage << "\n";
    cout << "Defence: " << defence << "\n";
    cout << "Range: " << range << endl;
}


