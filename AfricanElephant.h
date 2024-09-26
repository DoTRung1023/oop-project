#ifndef AFRICAN_ELEPHANT
#define AFRICAN_ELEPHANT

#include "Animal.h"

class AfricanElephant: public Animal{
    public:
        AfricanElephant(); 
        string getName();
        void setName(string name); 
};

#endif