#pragma once
#include "BinaryTreeSearchTester.h"


BinaryTreeSearchTester::BinaryTreeSearchTester(int size)
{
	m_maxSize = size;
	test(size);
}

BinaryTree* BinaryTreeSearchTester::allocateTree() {
	return new BinaryTreeSearch();
}

void BinaryTreeSearchTester::test(const int size)
{
	m_maxSize = size;
	addAndCount();
	destructor();
	remove();
	clear();
	assign();
	height();
}

void BinaryTreeSearchTester::isSearchTree(const BinaryTree& tree)
{
	std::vector<int> nodeKeys = tree.getVector();

	for (int i = 0; i < int(nodeKeys.size()) - 1; i++)
	{
		assert((nodeKeys[i]) <= (nodeKeys[i + 1])); 
	}
}

void BinaryTreeSearchTester::check_addAndCount(const BinaryTree* tree, const int size)
{
	BinaryTreeTester::check_addAndCount(tree, size);
	isSearchTree(*tree);
}


void BinaryTreeSearchTester::check_assign(const BinaryTree* tree1, const BinaryTree* tree2)
{
	BinaryTreeTester::check_assign(tree1, tree2);
	isSearchTree(*tree1);
	isSearchTree(*tree2);
}

void BinaryTreeSearchTester::check_remove(const BinaryTree* tree, const int size) {

	BinaryTreeTester::check_remove(tree, size);
	isSearchTree(*tree);
}
