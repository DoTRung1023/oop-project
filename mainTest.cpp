#include<iostream>
#include "TestDog.h"
#include "TestMice.h"
#include "TestElephant.h"


int main(){
    //Test Dog class: 
    cout << "Test Dog Class" << endl ;
    TestDog test1; 
    test1.runTestDog(); 

    //Test Mice class: 
    cout << endl; 
    cout << "Test Mice Class" << endl ;
    TestMice test2; 
    test2.runTestMice(); 

    //Test Elephant class: 
    cout << endl; 
    cout << "Test Elephant Class" << endl ;
    TestElephant test3; 
    test3.runTestElephant(); 
    return 0;
}