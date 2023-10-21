#include "BinaryTreeSearch.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	
	BinaryTreeSearch bts1 = BinaryTreeSearch();
		bts1.addNode(8);
		bts1.addNode(6);
		bts1.addNode(7);
		bts1.addNode(4);
		bts1.addNode(44);
		bts1.addNode(2);
		bts1.addNode(5);
		bts1.addNode(13);
		bts1.addNode(10);
		bts1.addNode(66);
		bts1.addNode(76);
		bts1.addNode(26);
		bts1.addNode(36);
		bts1.addNode(96);
		BinaryTreeSearch bts2(bts1);
		std::cout << "First tree: " << std::endl;
		bts1.print();
		std::cout << "Second tree: " << std::endl;
		bts2.print();

		cout << "Max:" << std::endl;
		cout << bts2.getMaxKey() << std::endl;
		cout << "Min:" << std::endl;
		cout << bts2.getMinKey() << std::endl;
		if (bts2.search(2)) {
			std::cout << "I find!" << std::endl;
		}
		else {
			std::cout << "Sorry" << std::endl;
		}

		BinaryTree bts = BinaryTree();
		bts.addNode(8);
		bts.addNode(6);
		bts.addNode(7);
		bts.addNode(4);
		bts.addNode(44);
		
		cout << endl;
		BinaryTreeSearch test = BinaryTreeSearch();
		test.addNode(5);
		test.addNode(10);
		test.addNode(4);
		test.addNode(3);
		test.addNode(22);
		test.addNode(12);
		test.addNode(2);
		test.addNode(11);
		
		test.print();

		cout << "Min Key in tree "<< test.getMinKey() << endl;
		cout << "Min Node in tree "<< test.getMinNode() << " or " << test.getMinNode()->getKey() << endl;

		cout<<test.deleteNode(12);

		test.print();

		cout <<"Tree Search 2:" << endl;

		BinaryTreeSearch test1 = test;
		//test1 = test;
	
		
		test1.print();


		cout << " not =" << endl;
		bts1.print();
		cout << "=" << endl;
		bts1 = test1;
		bts1.print();
	
		cout << "Height: "<<endl;
		cout<<bts1.getHeight()<<endl;
		cout << "Level"<<endl;
		cout << bts1.getlevelNode(100)<<endl;

	return 0;
}



/*
bool SearchTree::delete_by_key(Node*& root, const int key) {
  bool isDeleted = false;
  root = removeNode(root, key, isDeleted);
  return isDeleted;
}

Node* SearchTree::removeNode(Node* root, const int key, bool& isDeleted) {
  if (!root) {
	return nullptr;
  }
  if (key < root->key()) {
	root->left(removeNode(root->left(), key, isDeleted));
  }
  else if (key > root->key()) {
	root->right(removeNode(root->right(), key, isDeleted));
  }
  else {
	isDeleted = true;
	if (!root->left()) {
	  Node* right = root->right();
	  delete root;
	  return right;
	}
	else if (!root->right()) {
	  Node* left = root->left();
	  delete root;
	  return left;
	}
	else {
	  Node* replacementNode = root->right();
	  Node* parentNode = nullptr;

	  while (replacementNode->left()) {
		parentNode = replacementNode;
		replacementNode = replacementNode->left();
	  }

	  if (!parentNode) {
		replacementNode->left(root->left());
		delete root;
		return replacementNode;
	  }

	  parentNode->left(replacementNode->right());
	  replacementNode->left(root->left());
	  replacementNode->right(root->right());
	  delete root;
	  return replacementNode;
	}
  }
  return root;
}
*/



