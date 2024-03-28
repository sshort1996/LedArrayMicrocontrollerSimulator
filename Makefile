# Target: Names of the executable files
# TGT_LED = bin/ledArray
TGT_MCL = bin/microLogic
TGT_MCM = bin/microMem
TGT_MAIN = bin/main

# Compilers: Adjust paths if needed
CPP = g++
C = gcc

# Flags: Adjust as needed
CFLAGS = -Wall

# Source files: Specify both C and C++ files
# SRC_LED = src/ledArray/ledArray.cpp
SRC_MCL = src/MicroController/microLogic.cpp
SRC_MCM = src/MicroController/microMem.cpp
SRC_MAIN = src/main.cpp

# Main rule: Build all executables
all: $(TGT_MCL) $(TGT_MCM) $(TGT_MAIN)

# Rule to build the openMP executable
$(TGT_MAIN): $(SRC_MAIN)
	$(CPP) -fopenmp $(CFLAGS) -o $(TGT_MAIN) $(SRC_MAIN)

# Rule to build the MicroController modules
$(TGT_MCL): $(SRC_MCL)
	$(CPP) $(CFLAGS) -o $(TGT_MCL) $(SRC_MCL)

# Rule to build the MicroController modules
$(TGT_MCM): $(SRC_MCM)
	$(CPP) $(CFLAGS) -o $(TGT_MCM) $(SRC_MCM)

# Rule to build the LED array (SDL2) module
# $(TGT_LED): $(SRC_LED)
# 	$(C) $(CFLAGS) -o $(TGT_LED) $(SRC_LED)

# Clean rule: Remove executables
clean:
	rm -rf bin/*
