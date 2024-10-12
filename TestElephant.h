#ifndef TEST_ELEPHANT_H
#define TEST_ELEPHANT_H
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

class TestElephant{
    public: 
        void runTestElephant(){
            TestConstructor(); 
            testAttack();
            testDestructor(); 
        }
    private:
        void TestConstructor(); 
        void testAttack(); 
        void testDestructor(); 
};

#endif