#ifndef TEST_DOG_H
#define TEST_DOG_H
#include "Character.h"
#include "Dog.h"
#include "Mice.h"
#include "Elephant.h"

class TestDog{
    public: 
        void runTestDog(){
            TestConstructor(); 
            testAttack();
            testDestructor(); 
            testColor();
        }
    private:
        void TestConstructor(); 
        void testAttack(); 
        void testDestructor(); 
        void testColor();
};

#endif
