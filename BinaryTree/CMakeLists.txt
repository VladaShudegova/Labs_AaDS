cmake_minimum_required(VERSION 3.27)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BinaryTree
        BinaryTree.cpp
        BinaryTree.h
        BinaryTreeTester.cpp
        BinaryTreeTester.h
        main.cpp)
