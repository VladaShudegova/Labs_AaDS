#pragma once

#include "BinaryTreeSearch.h"
#include "BinaryTreeSearchTester.h"



using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(0));

    std::vector<int> keys       = { 5, 11, 19, 21, 23, 38, 44};
    std::vector<int> freq       = {10,  1,  1, 500,  1, 100, 1};
    std::vector<int> extraFreq = {10,  1,  221,  101, 10, 0,   0, 0};

    BinaryTreeSearch tree;
    tree = BinaryTreeSearch::createOptimalTree(keys , freq , extraFreq);

    tree.print();
    cout << endl;


	return 0;
}


