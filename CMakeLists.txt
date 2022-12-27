cmake_minimum_required(VERSION 3.20)
project(InterestCalculator)
# get all .c files recursesively from ./src
file(GLOB_RECURSE Sources RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
# cramble all source into one binary
add_executable(InterestCalc ${Sources})
