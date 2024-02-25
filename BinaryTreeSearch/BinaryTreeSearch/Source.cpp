#pragma once

#include "BinaryTreeSearch.h"
#include "BinaryTreeSearchTester.h"



using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(0));

    std::vector<int> keys = {5,19,23,38};
    std::vector<int> freq = {10,1,1,5};
    std::vector<int> extraFreq = {1,10,1,1,10};

    BinaryTreeSearch tree;
    tree.createOptimalTree(keys , freq , extraFreq);

    tree.print();
    cout << endl;


	return 0;
}


