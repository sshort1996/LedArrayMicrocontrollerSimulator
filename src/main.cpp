// This module will coordinate the microcontroller and
// led modules. This seems like a logical place to start. 
// First let's work out how to start other modules as a process 
// and say hello from each modules

#include <iostream>
#include <omp.h> 
#include <cstdlib>

using namespace std;

int main() {
    omp_set_num_threads(4); 

    #pragma omp parallel 
    {
        int threadID = omp_get_thread_num(); 
        switch (threadID) 
        {

        case 1:{
            int ret1 = system("bin\\memMod.exe");
            break;
        }
        case 2:{
            int ret2 = system("bin\\logMod.exe");
            break;
        }
        case 3:{
            int ret3 = system("bin\\ledArray.exe");
            break;
        }
        default:{
            cout << "Hello from the root process" << endl;
        }
        }

    } // End of the parallel region

    return 0;
}