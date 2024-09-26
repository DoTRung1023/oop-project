#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
    int atk;
    int hp;
    int def;
    string name;
    int equipmentID = -1;
public:
    Character();
    Character(int atk, int hp, int def, string name);
    void setImage(const char* filePath);
    virtual string getName();
    virtual void setName(string name);
    void setEquipment(int equipmentID);
    string getEquipmentName(int weaponID);
};

#endif
