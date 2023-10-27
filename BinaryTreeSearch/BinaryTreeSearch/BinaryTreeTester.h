#pragma once
#include <vector>
#include "BinaryTree.h"
#include <assert.h>

class BinaryTreeTester
{
public:
    BinaryTreeTester(const bool useConsoleOutput);
    BinaryTreeTester() = default;
    virtual ~BinaryTreeTester() = default;

    virtual void test( const int size);

protected:
    // service
    virtual BinaryTree* allocateTree();
    virtual void deallocateTree(BinaryTree* tree);
    void pressToContinue(const std::string& testName);

    // assertions
    virtual void check_addAndCount(const BinaryTree* tree, const int size);
    virtual void check_remove(const BinaryTree* tree, const int size);
    virtual void check_clear(const BinaryTree* tree, const int size);
    

    void check_assignPtr(const BinaryTree& left, const BinaryTree& right);
    void check_assignPtr(const BinaryTree::Node* left, const BinaryTree::Node* right);
    virtual void check_assign(const BinaryTree* tree1, const BinaryTree* tree2);
    virtual void check_assign(const std::vector<const BinaryTree::Node*> firstTreeNodes, const std::vector<const BinaryTree::Node*> secondTreeNodes);
    virtual void check_assignAndPtrs(const BinaryTree::Node* rootLeft, const BinaryTree::Node* rootRight);
    virtual void check_height(const BinaryTree& tree, const int size);

    // tests
    void addAndCount();
    void destructor();
    void remove();
    void clear();
    void assign();
    void height();
    void height_trivialCases();
    void height_longOnlyLeftSubtree();
    void height_longOnlyRightSubtree();
    void height_longOnlyLeftAndRightSubtrees();
    void height_longRandomZigzagSubtrees();

    std::vector<const BinaryTree::Node*> treeNodes(BinaryTree* tree);

protected:
    int m_maxSize;
    bool m_useConsoleOutput;
};