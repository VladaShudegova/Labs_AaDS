#include "BinaryTreeTester.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;

BinaryTreeTester::BinaryTreeTester(const bool useConsoleOutput)
        : m_useConsoleOutput(useConsoleOutput)
{}

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

BinaryTree *BinaryTreeTester::allocateTree()
{
    return new BinaryTree;
}

void BinaryTreeTester::deallocateTree(BinaryTree *tree)
{
    delete tree;
}

void BinaryTreeTester::addAndCount()
{
    BinaryTree *tree = allocateTree();
    check_addAndCount(tree, 0);

    for (int i = 0 ; i < m_maxSize; ++i) {
        tree->addNode(i);
        check_addAndCount(tree, i + 1);
    }

    deallocateTree(tree);
}

void BinaryTreeTester::check_addAndCount(const BinaryTree *tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::destructor()
{
    const int runsCount = 200;
    for (int i = 0; i < runsCount; i++)
    {
        BinaryTree* tree = allocateTree();
        for (int i = 0 ; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        deallocateTree(tree);
    }
    cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << endl;
    getchar();

}

void BinaryTreeTester::remove()
{
    int invalidKey = -1;
    std::vector<int> nodeKeys;

    BinaryTree* tree = allocateTree();
    tree->removeNode(invalidKey);
    check_remove(tree, nodeKeys.size());

    for (int i = 0 ; i < m_maxSize; ++i) {
        nodeKeys.push_back(i);
        tree->addNode(i);
    }

    while (!nodeKeys.empty()) {
        int removedNodeIndex = rand() % nodeKeys.size(); //3

        tree->removeNode(invalidKey);
        check_remove(tree, nodeKeys.size());
        cout<<"-----------------------Remove node whith key "<< nodeKeys[removedNodeIndex] <<"---------------------------------"<<endl;
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
    getchar();
}

void BinaryTreeTester::check_remove(const BinaryTree *tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::clear()
{
    BinaryTree* tree = allocateTree();
    for (int i = 0; i < 200; i++)
    {
        for (int i = 0 ; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        tree->clearTree();
        check_clear(tree, 0);
    }
    deallocateTree(tree);
    cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << std::endl;
    getchar();
}

void BinaryTreeTester::check_clear(const BinaryTree *tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::assign()
{
    BinaryTree tree1;

    for (int i = 0 ; i < m_maxSize; ++i) {
        tree1.addNode(i);
    }

    BinaryTree tree2 = tree1; //Конструктор копирования

    std::vector<BinaryTree::Node *> tree1Nodes = treeNodes(tree1);
    std::vector<BinaryTree::Node *> tree2Nodes = treeNodes(tree2);

    //FixMe: доделать проверку

    tree1 = tree2; //Присваивание

    tree1Nodes = treeNodes(tree1);
    tree2Nodes = treeNodes(tree2);

    //FixMe: доделать проверку
}

std::vector<const BinaryTree::Node *> BinaryTreeTester::treeNodes(const BinaryTree *tree)
{
    std::vector<const BinaryTree::Node *> nodes;

    std::queue<const BinaryTree::Node *> nodesToProcess;
    nodesToProcess.push_back(tree->root());
    while (!nodesToProcess.empty()) {
        const BinaryTree::Node *node = nodesToProcess.front();
        if (node != nullptr) {
            nodesToProcess.push(node->leftChild());
            nodesToProcess.push(node->rightChild());
            nodes.push_back(nodesToProcess);
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

void BinaryTreeTester::check_height(const BinaryTree &tree, const int height)
{
    assert(tree.getHeight() == height);
}

void BinaryTreeTester::height_trivialCases()
{
    BinaryTree tree;
    check_height(tree, 0);
    tree.addNode(0);
    check_height(tree, 1);
}

void BinaryTreeTester::height_longOnlyLeftSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node *runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setLeft(new BinaryTree::Node(i));
        runner = runner->getLeft();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyRightSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node *runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setRight(new BinaryTree::Node(i));
        runner = runner->getRight();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyLeftAndRightSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node *leftRunner = longTree.getRoot();
    BinaryTree::Node *rightRunner = longTree.getRoot();
    for (int i = 1; i < m_maxSize/2; ++i) {
        leftRunner->setLeft(new BinaryTree::Node(i));
        leftRunner = leftRunner->getLeft();
        check_height(longTree, i + 1);


        rightRunner->setRight(new BinaryTree::Node(i));
        rightRunner = rightRunner->getRight();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longRandomZigzagSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node *leftRunner = longTree.getRoot();
    BinaryTree::Node *rightRunner = longTree.getRoot();

    leftRunner->setLeft(new BinaryTree::Node(1));
    leftRunner = leftRunner->getLeft();
    rightRunner->setRight(new BinaryTree::Node(1));
    rightRunner = rightRunner->getRight();

    for (int i = 2; i < m_maxSize/2; ++i) {
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
}
