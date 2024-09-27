#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Equipment.h"

using namespace std;

class Character
{
private:
    Equipment* equipment;
protected:
    int atk;
    int hp;
    int def;
    string name;
public:
    Character();
    Character(int atk, int hp, string name);
    void setImage(const char* filePath);
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    void setEquipment(int equipmentID);
    virtual ~Character(); 
};

#endif
