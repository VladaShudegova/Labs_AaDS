cmake_minimum_required(VERSION 3.27)
project(BinaryTreeSearch)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        BinaryTree.h
        BinaryTree.cpp
        BinaryTreeSearch.h
        BinaryTreeSearch.cpp
        BinaryTreeSearchTester.h
        BinaryTreeSearchTester.cpp
        BinaryTreeTester.h
        BinaryTreeTester.cpp

        Source.cpp)