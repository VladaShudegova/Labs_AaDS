#pragma once
#include "BinaryTreeTester.h"
#include "BinaryTreeSearch.h"

class BinaryTreeSearchTester : public BinaryTreeTester {

public:
	BinaryTreeSearchTester(int size);
	BinaryTreeSearchTester() = default;
	
	~BinaryTreeSearchTester() override = default;

	void test(const int size) override;

protected:
	BinaryTree* allocateTree() override;
	void isSearchTree(const BinaryTree& tree);

	void check_addAndCount(const BinaryTree* tree, const int siaze) override;
	void check_assign(const BinaryTree* tree1, const BinaryTree* tree2) override;
	void check_remove(const BinaryTree* tree, const int size) override;


};