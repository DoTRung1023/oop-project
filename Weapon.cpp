#include <iostream>
#include "Equipment.h"
#include "Weapon.h"

using namespace std;

Weapon::Weapon(): Weapon(0, "", 0, 0, 0){}
Weapon::Weapon(int ID, string nameEquipment, int atk, int def, int range): 
                Equipment(ID, nameEquipment, "Weapon", atk, def), range(range){}
void Weapon::showInfo(){
    cout << "Name: " << nameEquipment << "\n";
    cout << "ID: " << ID << "\n";
    cout << "Damage: " << atk << "\n";
    cout << "Defence: " << def << "\n";
    cout << "Range: " << range << endl;
}


