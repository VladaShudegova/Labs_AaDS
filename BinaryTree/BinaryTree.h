#pragma once

/*
 * ����������� ������ ������ BinaryTree:
+ ������������ (�� ���������, �����������);
+ ����������;
+ ��������� ����� ������;
+ ������� ������ (�������� ���� �����);
+ �������� ����������� ����;
+ isEmpty (���������� true, ���� ������ �����);
+ ����������� ��������� ���� (���������� ����� ������ ������);
+ ��������� ������ ������;
+ ��������� ���������� ����� ������;
+ ��������� ������������/������������� ����� ������;
+ ���������� ���� � ������ (������� ���������� ������ ���������);
+ �������� ���� �� ������ �� ����� (���������� true, ���� ���� ��� �����);
+ �������� ������ �� ������������������ (���������� true, ���� ������ �������� ����������������: ������ ������� � ������ ����������� ���������� �� �����, ��� �� �������, � ���� ���������� ����� �������� �����������������);
+ ��������� ����� ���� ������ ������;
+ ��������� ������ ������� �� ����� (���������� ������ ������ ��� -1, ���� ������� �� �������);
+ ��������� ������� (std::vector<int>), ����������� ��� ����� ������ (����� ������ ����������� ����� ��������; �� ������ "�������" - ����� ����������� � ������� ���������);
+ ����� � ������� ������ � �������������� ���� (����� ������ ������� ��������� �� ������ ������, ����� ����� - �� ������);
-+ ����� � ������� ������ ������ ("������" ���� ��� �� �������, �.�., ����� ����� ����� ������ ������ ���������: 2^(������ ������));
-+ ����� � ������� ������ �� ������� (����� ���������������� ������ ����������� ������);
+ ����� � ������� ������� ������;
+ �������� ������������.
������ ������ ������ �������� ��� ��� ����� ������, ��� � ��� ������ �� ��� ����������� (��������, ���� � ����� ��������� ������� ������ �������� �� ������, � ���� �� �������� �����, ����� �������� ���������� ����� ��� ��������� � ������ � ���� ����).
 */

#include <iostream>
#include <vector>


class BinaryTree {

public:
    class Node;

    BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree(int key);
    BinaryTree(Node* root);
    ~BinaryTree();

    Node* getRoot();

    Node* addNode(Node* root, int key);
    Node* addNode(int key);

    void deleteChildren(Node* node);
    void clearTree();

    bool isEmpty() const;

    BinaryTree copyBinaryTree(Node* node);

    int getHeight() const;

    int getHeight(Node* node) const;

    int size() const;

    int getCount(const Node* node) const;

    int getMaxKey();

    int getMaxKey(Node* node);

    int getMinKey();

    int getMinKey(Node* node);

    bool removeNode(int key);

    bool remove(Node* node, int key, Node* parent);

    Node* search(int key) const;

    Node* search(Node* node, int key) const;

    std::vector<int> getVector() const;

    void getVector(Node* node, std::vector<int>& result) const;

    int getLevel(int key);

    int getLevel(Node* node, int key);

    bool isBalanced(Node* node);

    int getSum() const;

    int getSum(Node* node) const;

    void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;
    
    void print() const;

    void printLevel(int level) const;

    void printByLevels(Node* root) const;

    BinaryTree& operator=(const BinaryTree& other);

private:
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
