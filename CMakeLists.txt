cmake_minimum_required(VERSION 3.21)
project(power_quality_analyser C)

set(CMAKE_C_STANDARD 99)

add_executable(power_quality_analyser
        main.c
        waveform.c
        io.c)


