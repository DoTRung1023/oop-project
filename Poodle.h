#ifndef POODLE_H
#define POODLE_H
#include "Animal.h"

class Poodle: public Animal{
    public: 
        Poodle(); 
        string getName();
        void setName(string name); 
};

#endif