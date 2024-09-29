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
protected:
    int atk;
    int hp;
    string name;
    Equipment* equipment;
public:
    Character();
    Character(int atk, int hp, string name);
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual int getAtk() = 0;
    virtual void setAtk(int atk) = 0;
    virtual int getHp() = 0;
    virtual void setHp(int hp) = 0;
    void setEquipment(int equipmentID);
    virtual ~Character(); 
};

#endif
