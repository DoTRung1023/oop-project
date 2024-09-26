#include<iostream>
using namespace std; 


int main(){
    int** numberList = new int*[3]; 
    for(int i = 0; i<3; i++){
        numberList[i] = new int(i); 
    }

    
    for(int i = 0; i<3; i++){
        delete numberList[i]; 
    }
    delete[] numberList; 

    return 0; 
}