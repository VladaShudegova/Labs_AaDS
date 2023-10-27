#pragma once
#include "BinaryTree.h"



class BinaryTreeSearch: 
	public BinaryTree
{
public:
	using BinaryTree::Node;
	BinaryTreeSearch() : BinaryTree() {};
	BinaryTreeSearch(const BinaryTreeSearch& other) :BinaryTree(other) {};
	BinaryTreeSearch(Node* root);

	~BinaryTreeSearch() override = default;

	BinaryTreeSearch copyBinaryTreeSearch(Node* node);
	
	Node* addNode(int key) override;
	Node* addNode(Node* root, int key) override;

	int getMaxKey() const override;
	virtual int getMaxKey(Node* node) const override;

	int getMinKey() const override;
	virtual int getMinKey(Node* node) const override;

	Node* getMinNode() const;
	Node* getMinNode(Node* node) const;

	Node* getMaxNode() const;
	Node* getMaxNode(Node* node) const;


	Node* search(const int key) const override;
	Node* search(Node* node, const int key) const override;

	bool deleteNode(Node*& node, const int key);
	bool deleteNode(const int key);

	Node* removeNode(Node* node, int key, bool& isDeleted);

	int getlevelNode(const int key);

	BinaryTreeSearch& operator=(const BinaryTreeSearch& other);
	
};


