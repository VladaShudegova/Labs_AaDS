cmake_minimum_required(VERSION 3.27)
project(HashFunction)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashFunction main.cpp
        cmake-build-debug/HashTable.cpp
        cmake-build-debug/HashTable.h
)
