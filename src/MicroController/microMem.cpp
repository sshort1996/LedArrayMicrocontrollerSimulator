// This module will contain the logic for mallocing a block of memory and sharing 
// it with our other processes. 
#include <iostream>
#include <cstdlib>
#include "../../include/microMem.h"
using namespace std;

int* mallocArray(int m, int n){
    int* arr = static_cast<int*>(malloc(m * n * sizeof(int)));
    if (!arr){
        cerr << "Malloc failed" << endl;
        return nullptr;
    }
    return arr;
}

int returnAddresses() {
    int m = 5;
    int n = 5;
    
    int *ledArray = mallocArray(m, n);
    
    for (int i = 0; i < m * n; ++i){
        cout << "Address of 'LED': " << i << ": " << &ledArray[i] << endl;
    }
    
    free(ledArray);
    
    return 0;
}