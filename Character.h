#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
    protected:
        int atk;
        int hp; 
    public:
        Character(int atk, int hp); 
        Character(); 
        virtual void status(Character* character) = 0; 
        // virtual void move(): Todo
        virtual int attack(Character* target); 
};

#endif