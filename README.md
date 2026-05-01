# Power Quality Analyser

## Description
This project is a C-based program that analyses power quality waveform data.
It processes input data from a file and performs analysis on voltage/current signals.

## GitHub Repository
https://github.com/SultanAlWaalan/power_quality_analyser

## How to Compile and Run

### Using GCC:
gcc main.c io.c waveform.c -o analyser
./analyser

### Using CMake:
mkdir build
cd build
cmake ..
make
./analyser

## Files Included
- main.c → main program
- io.c / io.h → file input/output
- waveform.c / waveform.h → waveform processing
- CMakeLists.txt → build configuration

## Notes
- Make sure your system supports C99 standard
