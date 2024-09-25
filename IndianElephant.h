#ifndef INDIAN_ELEPHANT_H
#define INDIAN_ELEPHANT_H
#include "Animal.h"

class IndianElephant: public Animal{
    public:
        IndianElephant(); 
        string getName();
        void setName(string name); 
};

#endif