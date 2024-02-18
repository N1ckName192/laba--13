cmake_minimum_required(VERSION 3.26)
project(dismath C)

set(CMAKE_C_STANDARD 11)

add_executable(dismath
        bitset/bitset_test.c
        bitset/bitset.h
        bitset/bitset.c
        util.h
        util.c
        unordered_array/unordered_array.h
        unordered_array/unordered_array.c
        unordered_array/unordered_array_test.c
        ordered_array/ordered_array.h
        ordered_array/ordered_array.c
        ordered_array/ordered_array_test.c
        codeforces/solutions.c
)