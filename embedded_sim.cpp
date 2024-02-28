// Make a simulated LED array using memory addresses, on a real 
// microcontroller these addresses would be linked to GP/IO pins
// controlling LED's. In our programme they will just be magic 
// addresses assigned to the heap and the value of these addresses 
// will be displayed in a window as the brightness of an LED
// (brightness will likely just be a 1 or 0)
#include <iostream>
using namespace std;

int main(){
    // malloc a chunk of memory for an n*n 'LED array'
    // int[n] *chunk = (*int)malloc...something 
    int n = 5; // Example size, can be any value
    int** array = new int*[n]; // Allocate memory for n pointers to int

    // return the addresses ie 
    cout << "Addresses assigned at: " << &array;

    delete[] array; // free the array of pointers 
    // visualise the set of addresses in a window

    // control the values of these addresses from another programme, ie. our 'microcontroller' code
}


// This code should actually just be checking the values of the addresses and displaying them
// This code should never write any values to these addresses, as that would be equivalent to 
// our microcontroller LED's writing to system memory.