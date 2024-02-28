I want to build an embedded led array simulator. I want to write two programmes in C or C++. One programme will act as my microcontroller, and read the values of 64 memory addresses and display their values on an 8*8 grid in a window as if they were real physical LED's. The other programme which will be running at the same time will contain the code that would run on my microcontroller and control the values of the memroy addresses, ie. the LED's. Is this sometjing I can do in C++?

Yes, you can certainly build an embedded LED array simulator with two programs in C or C++ that communicate with each other to simulate the behavior of a microcontroller driving an LED array. This project involves inter-process communication (IPC), graphical user interface (GUI) programming for the LED display, and potentially multithreading depending on how you structure your programs. Here's a high-level overview of how you might approach this:

### Program 1: The LED Array Simulator

This program will simulate the 8x8 LED grid. It needs to:

1. **Create a GUI Window**: Use a GUI library that's compatible with C or C++, such as Qt (C++), GTK (C), or SDL (C/C++), to create a window that represents the 8x8 LED grid. Each LED can be a small square that changes color based on the value of the corresponding memory address.

2. **Read Shared Memory**: This program will read from a block of shared memory that both this program and the microcontroller simulator can access. The values read from this memory will determine the state (on/off, or even color if you're simulating multi-color LEDs) of each LED in the grid.

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

### Steps to Get Started

1. **Choose Your Libraries**: Decide on the libraries you'll use for GUI development and IPC based on your platform and language preference (C vs. C++).
2. **Design the Communication Protocol**: Plan how your programs will communicate through shared memory. Decide on the layout of the memory and how changes will be detected.
3. **Implement the Microcontroller Simulator**: Start by writing the logic that controls the LEDs, using shared memory to represent the LED states.
4. **Implement the LED Array Simulator**: Create the GUI application that reads the shared memory and visually represents the LED states.
5. **Test and Debug**: Run both programs simultaneously, debug any issues, and refine the simulation.

This project is a fantastic way to learn about IPC, GUI programming, and simulating hardware with software. It's complex enough to be challenging but well within reach with some effort and learning.