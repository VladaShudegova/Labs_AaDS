cmake_minimum_required(VERSION 3.23)
project(Labs_Tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(Labs_Tree
        main.cpp
        Node.cpp
        Node.h
        BinaryTree.cpp
        BinaryTree.h
        BinaryTreeTester.cpp
        BinaryTreeTester.h)
