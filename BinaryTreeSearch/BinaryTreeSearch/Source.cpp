#pragma once

#include "BinaryTreeSearch.h"
#include "BinaryTreeSearchTester.h"



using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(0));

    std::vector<int> keys = {10,20,30,40};
    std::vector<int> freq = {2,1,1,5};
    std::vector<int> extraFreq = {1,10,1,1,10};

    BinaryTreeSearch tree;
    tree.createOptimalTree(keys , freq , extraFreq);


	//BinaryTreeSearchTester test;
	//test.test(220);

	return 0;
}


