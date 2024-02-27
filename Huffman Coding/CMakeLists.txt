cmake_minimum_required(VERSION 3.27)
project(Huffman_Coding)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Huffman_Coding
        HuffmanTree.cpp
        HuffmanTree.h
        main.cpp
        Node.cpp)
