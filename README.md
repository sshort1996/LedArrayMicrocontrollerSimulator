# Embedded LED Array and microcontroller simulator
This project will be split into two parts
 1. A simulated array of LED's, represented by memory addresses virtually linked to GP/IO headers. By monitoring the values of these memory addresses, a window will display a grid of LED's turned either on or off. The addresses will be shared with the programme dynamically by the second part of the project, the microcontroller simulator.
 2. A simulated microcontroller code, which mallocs a contiguous block of memory to represent the LED array, and controls the values of the arrays through some mechanism, perhaps displaying the time, maybe the temperature, just some data. The trick here will be sharing the memory addresses with the 'LED array'. This component may itself be split into two submodules
    - A module who's sole responsibility is retreiving memory and sharing it with the microcontroller and LED code.
    - A module meant to simulate the microcontroller as closely as possible, containing only the logic for manipulating the 'GP/IO header' addresses 



## Project directory structure 
 - src/: Contains the project's source code files (.cpp). For larger projects, consider organizing these files into subdirectories that reflect the project's modular structure or components.


 - include/: Contains all the header files (.h or .hpp). This separation from source files helps manage dependencies and improves build times. Use subdirectories to organize headers related to specific modules or functionalities.


 - lib/: External libraries that your project depends on. You might compile these from source or include pre-compiled binaries. Consider using a package manager like Conan or vcpkg to manage these dependencies.


 - bin/: The output directory for the final executable(s) or binary(ies) produced by the project. This keeps the build artifacts separate from the source code.


### Program 1: The LED Array Simulator

This program will simulate the 8x8 LED grid. It needs to:

1. **Create a GUI Window**: Use a GUI library that's compatible with C or C++, such as Qt (C++), GTK (C), or SDL (C/C++), to create a window that represents the 8x8 LED grid. Each LED can be a small square that changes color based on the value of the corresponding memory address.

2. **Read Shared Memory**: This program will read from a block of shared memory that both this program and the microcontroller simulator can access. The values read from this memory will determine the state (on/off, or color) of each LED in the grid.

3. **Update the Display**: Continuously poll the shared memory for changes and update the GUI to reflect the current state of each LED.

### Program 2: The Microcontroller Simulator

This program simulates the microcontroller code that controls the LEDs. It will:

1. **Write to Shared Memory**: This program controls the LED states by writing values to the same block of shared memory that the LED array simulator is reading from. The values written here represent the state of each LED.

2. **Simulate Microcontroller Logic**: Implement the logic that you would normally run on the microcontroller to control the LEDs. This could involve patterns, responding to simulated input, etc.

### Shared Memory for IPC

For the two programs to communicate, you'll use a form of IPC. Shared memory is a good choice for this project because it allows fast, direct access to a common block of memory by both programs. In C++, you might use platform-specific APIs (e.g., POSIX shared memory on Unix-like systems, or Windows shared memory APIs) or a cross-platform IPC library that supports shared memory.

### Example Libraries and APIs

- **GUI Programming**: Qt (C++) is very powerful for cross-platform GUI applications. SDL is another good choice, especially if you want something more lightweight.
- **IPC (Shared Memory)**: Boost.Interprocess (C++) offers portable shared memory functionality. POSIX shared memory (`shm_open`, `mmap`, etc.) is an option on Unix-like systems, while Windows offers its own shared memory APIs.
- **Multithreading (if needed)**: If your microcontroller simulator needs to perform multiple tasks concurrently (e.g., reading simulated input while controlling LEDs), you might need threading. C++11 and later include threading support in the standard library (`<thread>`), or you can use POSIX threads (pthreads) in C.


## Building the project
We should probably learn a build system for compiling all this, let's go with Cmake. Each file is compiled as follows:
 ### `/main.cpp`
 ```
 g++ -fopenmp src/main.cpp -o bin/main
 ```
 ### `/MicroController/microLogic.cpp`
 ```
 g++ src/MicroController/microLogic.cpp -o bin/logMod
 ```
 ### `/MicroController/microMem.cpp`
```
g++ src/MicroController/microMem.cpp -o bin/memMod
```
### `ledArray/ledArray.cpp`
SDL2, working on it

## Header files and function pointers
The current design of the main module is dumb, we should refactor the microMem, and microLogic modules to use a header file to initialise the methods in each, and a source file defining these functions. More info [here](https://stackoverflow.com/questions/51488008/how-can-i-call-functions-from-one-cpp-file-in-another-cpp-file).
