
#pragma once
#include <iostream>
#include <vector>


class BinaryTree {

public:
    class Node;

    BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree(int key);
    BinaryTree(Node* root);
    virtual ~BinaryTree();

    Node* getRoot();

    virtual Node* addNode(int key);
    virtual Node* addNode(Node* root, int key);

    void deleteChildren(Node* node);
    void clearTree();

    bool isEmpty() const;

    BinaryTree copyBinaryTree(Node* node);

    int getHeight() const;
    int getHeight(Node* node) const;

    int size() const;

    int getCount(const Node* node) const;

    virtual int getMaxKey() const;
    virtual int getMaxKey(Node* node) const;

    virtual int getMinKey() const;
    virtual int getMinKey(Node* node) const;


    virtual bool removeNode(const int key);
    virtual bool removeNode(Node* node, const int key, Node* parent);



    virtual Node* search(const int key) const;
    virtual Node* search(Node* node, const int key) const;

    std::vector<int> getVector() const;


    void getVector(Node* node, std::vector<int>& result) const;

    int getLevel(const int key) const;
    virtual int getLevel(Node* node, const int key) const;

    bool isBalanced(Node* node) const;

    int getSum() const;
    int getSum(Node* node) const;

    void printHorizontal(Node* root, const int marginLeft, const int levelSpacing) const;
    void print() const;
    void printLevel(int level) const;
    void printByLevels(Node* root) const;

    BinaryTree& operator=(const BinaryTree& other);

protected:
    Node* m_root;

};



class BinaryTree::Node
{
public:
    explicit Node(int key = 0) {
        m_key = key;
        m_left = nullptr;
        m_right = nullptr;
    }

    Node(int key, Node* left, Node* right) {
        m_key = key;
        m_left = left;
        m_right = right;
    }
    Node* getLeft() const {
        return m_left;
    }

    void setLeft(Node* left) {
        m_left = left;
    }

    Node* getRight() const {
        return m_right;
    }

    void setRight(Node* right) {
        m_right = right;
    }

    int getKey() const {
        return m_key;
    }

    void setKey(int key) {
        m_key = key;
    }

    int getNumChildren() const {
        return (m_left != nullptr) + (m_right != nullptr);
    }

    Node* copyNode() {
        return copyNode(this);
    }

    Node* copyNode(Node* node) {
        Node* newNode = new Node(node->m_key);
        if (node->m_left != nullptr) {
            newNode->m_left = copyNode(node->m_left);
        }
        if (node->m_right != nullptr) {
            newNode->m_right = copyNode(node->m_right);
        }
        return newNode;
    }

private:
    Node* m_left;
    Node* m_right;
    int m_key;
};


