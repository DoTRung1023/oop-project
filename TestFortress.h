#ifndef TEST_FORTRESS_H
#define TEST_FORTRESS_H


class TestFortress{
    public: 
        void runTestFortress(){
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
