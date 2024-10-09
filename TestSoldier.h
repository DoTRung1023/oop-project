#ifndef TEST_SOLDIER_H
#define TEST_SOLDIER_H


class TestSoldier{
    public: 
        void runTestSoldier(){
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

