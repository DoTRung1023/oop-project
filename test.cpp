#include<iostream>
#include "Dog.h"
#include "Animal.h"


int main(){
    Dog d1; 
    cout <<d1.getName() << endl; 
    d1.setName("hello"); 
    cout << d1.getName() << endl;
    return 0; 
}