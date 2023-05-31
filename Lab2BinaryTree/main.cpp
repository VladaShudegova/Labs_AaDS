#include <iostream>
#include <vector>

#include "BinaryTree.h"
#include "BinaryTreeTester.h"
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;


BinaryTree::Node* ten_child_tree() {
    BinaryTree::Node* one = new BinaryTree::Node(1);
    BinaryTree::Node* two = new BinaryTree::Node(2);
    BinaryTree::Node* three = new BinaryTree::Node(3);
    BinaryTree::Node* four = new BinaryTree::Node(4);
    BinaryTree::Node* five = new BinaryTree::Node(5);
    BinaryTree::Node* six = new BinaryTree::Node(6);
    BinaryTree::Node* seven = new BinaryTree::Node(7);
    BinaryTree::Node* eight = new BinaryTree::Node(8);
    BinaryTree::Node* nine = new BinaryTree::Node(9);
    BinaryTree::Node* ten = new BinaryTree::Node(10);

    one->setLeft(two);
    one->setRight(three);
    two->setLeft(four);
    two->setRight(five);
    five->setRight(seven);
    three->setRight(six);
    six->setRight(eight);
    eight->setLeft(nine);
    eight->setRight(ten);

    return one;
}


void printLeaves(BinaryTree::Node* node) {
    if (node == nullptr) {
        return;
    }
    if (node->getLeft() == nullptr && node->getRight() == nullptr) {

        cout << node->getKey() << " ";
    }
    else {
        printLeaves(node->getLeft());
        printLeaves(node->getRight());
    }
}
void refillAndPrint(BinaryTree &tree)
{
    tree.clearTree();
    int count = 5;
    int stepSize = 10;
    int min = 0;
    int max = min + stepSize * count;
    for (int key = min; key <= max; key += stepSize) {
        tree.addNode(tree.getRoot(), key);
    }
    tree.printHorizontal(tree.getRoot(), 5, 5);
}

int main()
{
    BinaryTreeTester tester(true);
    tester.test(30);

    BinaryTree tree = ten_child_tree();
    tree.printHorizontal(tree.getRoot(), 5,5);
    return 0;
}
