# Compiler settings
CXX=g++
CXXFLAGS=-fopenmp
LDFLAGS=

# Executable name
TARGET=ESLED

# Source directories
SRC_DIR=src
MICRO_DIR=src/MicroController
LED_DIR=src/ledArray

# Object files
OBJS=$(SRC_DIR)/main.o $(MICRO_DIR)/microLogic.o $(MICRO_DIR)/microMem.o $(LED_DIR)/ledArray.o
# Default target
all: $(TARGET)
# Linking the program
$(TARGET): $(OBJS)
    $(CXX) -o $@ $^ $(LDFLAGS)
# Compiling main.cpp with C++ compiler
$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
# Compiling microcontroller logic module
$(MICRO_DIR)/microLogic.o: $(MICRO_DIR)/microLogic.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
# Compiling microcontroller memory module
$(MICRO_DIR)/microMem.o: $(MICRO_DIR)/microMem.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
# Compiling LED array module
$(LED_DIR)/ledArray.o: $(LED_DIR)/ledArray.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
# Clean target
clean:
    rm -f $(OBJS) $(TARGET)