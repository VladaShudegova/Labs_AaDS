#include "BinaryTreeTester.h"
#include <queue>
#include <random>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::queue;

BinaryTreeTester::BinaryTreeTester(const bool useConsoleOutput)
{
    m_useConsoleOutput = useConsoleOutput;
    m_maxSize = 0;
}


void BinaryTreeTester::test(const int size)
{
    m_maxSize = size;
    addAndCount();
    destructor();
    remove();
    clear();
    assign();
    height();
}

BinaryTree* BinaryTreeTester::allocateTree()
{
    return new BinaryTree;
}

void BinaryTreeTester::pressToContinue(const std::string& testName)
{
    cout << "BinaryTreeTester::" << testName << " ended. Press any key to continue..." << endl;

}

void BinaryTreeTester::deallocateTree(BinaryTree* tree)
{
    delete tree;
}

void BinaryTreeTester::addAndCount()
{
    BinaryTree* tree = allocateTree();
    check_addAndCount(tree, 0);

    for (int i = 0; i < m_maxSize; ++i) {

        tree->addNode(rand() % 350 - 100);
        check_addAndCount(tree, i + 1);
    }

    deallocateTree(tree);

    pressToContinue("addAndCound");
}

void BinaryTreeTester::check_addAndCount(const BinaryTree* tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::destructor()
{
    const int runsCount = 200;
    for (int i = 0; i < runsCount; i++)
    {
        BinaryTree* tree = allocateTree();
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(rand() % 350 - 100);
        }
        deallocateTree(tree);
    }

    pressToContinue("destructor");
}

void BinaryTreeTester::remove()
{
    int invalidKey = -1;
    std::vector<int> nodeKeys;

    BinaryTree* tree = allocateTree();
    tree->removeNode(invalidKey);
    check_remove(tree, nodeKeys.size());

    for (int i = 0; i < m_maxSize; ++i) {
        int temp = rand() % 350 - 100;
        nodeKeys.push_back(temp);
        tree->addNode(temp);
    }

    while (!nodeKeys.empty()) {
        int removedNodeIndex = rand() % nodeKeys.size(); //3

        tree->removeNode(invalidKey);
        check_remove(tree, nodeKeys.size());
        cout << "-----------------------Remove node with key " << nodeKeys[removedNodeIndex] << "---------------------------------" << endl;
        tree->removeNode(nodeKeys[removedNodeIndex]);
        nodeKeys.erase(nodeKeys.begin() + removedNodeIndex);
        check_remove(tree, nodeKeys.size());

        if (m_useConsoleOutput)
            tree->print();
    }
    if (m_useConsoleOutput)
        tree->print();
    tree->removeNode(invalidKey);
    check_remove(tree, nodeKeys.size());
    deallocateTree(tree);
    cout << "BinaryTreeTester::remove ended. Press any key to continue..." << endl;

}

void BinaryTreeTester::check_remove(const BinaryTree* tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::clear()
{
    BinaryTree* tree = allocateTree();

    for (int i = 0; i < m_maxSize; i++)
        tree->addNode(rand() % 350 - 100);

    check_clear(tree, m_maxSize);

    tree->clearTree();
    check_clear(tree, 0);

    deallocateTree(tree);

    pressToContinue("clear");
}

void BinaryTreeTester::check_clear(const BinaryTree* tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::assign()
{
    BinaryTree* tree1 = allocateTree();
    BinaryTree* tree2 = allocateTree();

    for (int i = 0; i < m_maxSize; ++i)
        tree1->addNode(rand() % 350 - 100);

    *tree2 = *tree1;
    check_assign(treeNodes(tree1), treeNodes(tree2));

    *tree1 = *tree2;
    check_assign(treeNodes(tree1), treeNodes(tree2));

    deallocateTree(tree1);
    deallocateTree(tree2);
    pressToContinue("assign");
}

std::vector<const BinaryTree::Node*> BinaryTreeTester::treeNodes(BinaryTree* tree)
{
    std::vector<const BinaryTree::Node*> nodes;

    queue<const BinaryTree::Node*> nodesToProcess;
    nodesToProcess.push(tree->getRoot());
    while (!nodesToProcess.empty()) {
        const BinaryTree::Node* node = nodesToProcess.front();
        if (node != nullptr) {
            nodesToProcess.push(node->getLeft());
            nodesToProcess.push(node->getRight());
            nodes.push_back(node);
        }
        nodesToProcess.pop();
    }

    return nodes;
}


void BinaryTreeTester::height()
{
    height_trivialCases();
    height_longOnlyLeftSubtree();
    height_longOnlyRightSubtree();
    height_longOnlyLeftAndRightSubtrees();
    height_longRandomZigzagSubtrees();
}

void BinaryTreeTester::check_assign(const std::vector<const BinaryTree::Node*> leftTreeNode, const std::vector< const BinaryTree::Node* > rightTreeNode)
{
    assert(leftTreeNode.size() == rightTreeNode.size());

    for (int i = 0; i < leftTreeNode.size(); i++)
    {
        assert(leftTreeNode[i] != rightTreeNode[i]);
        assert(leftTreeNode[i]->getKey() == rightTreeNode[i]->getKey());
    }
}

void BinaryTreeTester::check_height(const BinaryTree& tree, const int height)
{
    assert(tree.getHeight() == height);
}

void BinaryTreeTester::height_trivialCases()
{
    BinaryTree tree;
    check_height(tree, 0);
    tree.addNode(0);
    check_height(tree, 1);

    pressToContinue("height_trivialCases");
}

void BinaryTreeTester::height_longOnlyLeftSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setLeft(new BinaryTree::Node(i));
        runner = runner->getLeft();
        check_height(longTree, i + 1);
    }

    pressToContinue("height_longOnlyLeftSubtree");
}

void BinaryTreeTester::height_longOnlyRightSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setRight(new BinaryTree::Node(i));
        runner = runner->getRight();
        check_height(longTree, i + 1);
    }

    pressToContinue("height_longOnlyRightSubtree");
}

void BinaryTreeTester::height_longOnlyLeftAndRightSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* leftRunner = longTree.getRoot();
    BinaryTree::Node* rightRunner = longTree.getRoot();
    for (int i = 1; i < m_maxSize / 2; ++i) {
        leftRunner->setLeft(new BinaryTree::Node(i));
        leftRunner = leftRunner->getLeft();
        check_height(longTree, i + 1);


        rightRunner->setRight(new BinaryTree::Node(i));
        rightRunner = rightRunner->getRight();
        check_height(longTree, i + 1);
    }

    pressToContinue("height_longOnlyLeftAndRightSubtrees");
}

void BinaryTreeTester::height_longRandomZigzagSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* leftRunner = longTree.getRoot();
    BinaryTree::Node* rightRunner = longTree.getRoot();

    leftRunner->setLeft(new BinaryTree::Node(1));
    leftRunner = leftRunner->getLeft();
    rightRunner->setRight(new BinaryTree::Node(1));
    rightRunner = rightRunner->getRight();

    for (int i = 2; i < m_maxSize / 2; ++i) {
        if (rand() % 2 == 0)
        {
            leftRunner->setLeft(new BinaryTree::Node(i));
            leftRunner = leftRunner->getLeft();
        }
        else
        {
            leftRunner->setRight(new BinaryTree::Node(i));
            leftRunner = leftRunner->getRight();
        }
        check_height(longTree, i + 1);

        if (rand() % 2 == 0)
        {
            rightRunner->setLeft(new BinaryTree::Node(i));
            rightRunner = rightRunner->getLeft();
        }
        else
        {
            rightRunner->setRight(new BinaryTree::Node(i));
            rightRunner = rightRunner->getRight();
        }
        check_height(longTree, i + 1);
    }

    pressToContinue("height_longRandomZigzagSubtrees");
}

void BinaryTreeTester::check_assignPtr(const BinaryTree::Node* left, const BinaryTree::Node* right) {
    assert(left != right);
    if (left == nullptr || right == nullptr) {
        return;
    }
    check_assignPtr(left->getLeft(), right->getLeft());
    check_assignPtr(left->getRight(), right->getRight());

}

void BinaryTreeTester::check_assignPtr(const BinaryTree& left, const BinaryTree& right) {
    check_assignPtr(left.getRoot(), right.getRoot());
}

void BinaryTreeTester::check_assign(const BinaryTree* tree1, const BinaryTree* tree2) {
    assert(tree1->size() == tree2->size());

    const vector<int> tree1Keys = tree1->getVector();
    const vector<int> tree2Keys = tree1->getVector();

    assert(tree1Keys == tree2Keys);

    check_assignAndPtrs(tree1->getRoot(), tree2->getRoot());

}


 void BinaryTreeTester::check_assignAndPtrs(const BinaryTree::Node* rootLeft, const BinaryTree::Node* rootRight) {
     if (rootLeft == nullptr || rootRight == nullptr) {
         return;
     }

     assert(rootLeft->getKey() == rootRight->getKey());
     assert(rootLeft != rootRight);

     check_assignAndPtrs(rootLeft->getLeft(), rootRight->getLeft());
     check_assignAndPtrs(rootLeft->getRight(), rootRight->getRight());

}

